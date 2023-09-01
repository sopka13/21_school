/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_desc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:06:04 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:52:57 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Search '>' '>>' '<' characters and assign file descriptors
** 	return (0) - Success
** 	return (-1/-2) - Error
*/

#include "../minishell.h"

static int	ft_file_desc_rem_el(t_vars *vars, int *i)
{
	if (ft_strlen(vars->args[*i]) == 0)
	{
		if (!(vars->args = ft_rem_elem_arr(vars->args, vars->args[*i])))
			return (-2);
		*i = -1;
	}
	return (0);
}

static int	ft_file_desc_ret(t_vars *vars)
{
	if (vars->flags->error == 1)
		return (-1);
	return (ft_print(strerror(errno), -2));
}

static void	ft_file_desc_start(t_vars *vars, int *i)
{
	*i = -1;
	ft_init_flags(vars);
}

int			ft_file_desc(t_vars *vars, char *str)
{
	int		i;
	int		ret;
	char	*line;

	if (!(line = ft_strdup("")))
		return (ft_print(strerror(errno), -2));
	ft_file_desc_start(vars, &i);
	while (str[++i])
		if ((ret = ft_file_dc_s(vars, str, &line, &i)) != 0)
			return (ret);
	if (!(line = ft_echo_arg(vars, line)))
		return (-2);
	if (ft_strlen(line) == 0 || !ft_only_space(line, -1))
		return (-1);
	if (!(vars->args = ft_get_command(vars, line, ' ')))
		return (ft_file_desc_ret(vars));
	i = -1;
	while (vars->args[++i])
		if ((ret = ft_file_desc_rem_el(vars, &i)) == -2)
			return (-2);
	if ((ret = ft_rem_quotes(vars)) == -2)
		return (-2);
	free(line);
	return (0);
}
