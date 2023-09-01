/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:35:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:04:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Split command str with ';' and '&&' characters and start get_result func
** 	return (1) - Error
** 	return (0) - Success
*/

#include "../minishell.h"

static int	ft_parse_syntax_error(t_vars *vars)
{
	vars->flags->status = 2;
	return (ft_print("Syntax error", 0));
}

static int	ft_parse_caloc(t_vars *vars, int k)
{
	if (!(vars->com_l = ft_calloc(k + 1, sizeof(t_com*))))
		return (ft_print(strerror(errno), 1));
	vars->com_l[k] = NULL;
	return (0);
}

static int	ft_parse_if_1(t_vars *vars, char **com, int i)
{
	if (!(vars->com_l[i]->command = ft_get_command(vars, com[i], '&')) &&
		vars->flags->error == 0)
		return (1);
	return (0);
}

int			ft_parse(t_vars *vars)
{
	int		i;
	char	**com;
	int		k;

	if ((k = ft_num(vars, vars->str, ';')) == -1)
		return (ft_parse_syntax_error(vars));
	if (ft_parse_caloc(vars, k))
		return (1);
	if (!(com = ft_get_command(vars, vars->str, ';')) && !vars->flags->error)
		return (ft_print(strerror(errno), 1));
	if (vars->flags->error == 1)
		return (0);
	i = -1;
	while (com[++i])
	{
		vars->com_l[i] = ft_calloc(1, sizeof(t_com));
		if ((vars->com_l[i]->num = ft_num(vars, com[i], '&')) == -1)
			return (ft_parse_syntax_error(vars));
		if (ft_parse_if_1(vars, com, i))
			return (ft_print(strerror(errno), 1));
		if (vars->flags->error == 1)
			return (0);
	}
	ft_free_ss(com);
	return (ft_get_result(vars));
}
