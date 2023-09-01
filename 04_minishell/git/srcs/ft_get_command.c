/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:38:54 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 20:14:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Split str into command with 'a' character
** 	return (**arr) - Success
** 	return (NULL) - Error
*/

#include "../minishell.h"

static char	*ft_get_com_1(t_vars *vars, char *str, char a, t_temp_1 *tp)
{
	char	*str_1;

	if (!str || !(str_1 = ft_strdup(str)))
		return (NULL);
	if (ft_new_line_error(str, a) || (tp->num = ft_num(vars, str, a)) == -1)
	{
		vars->flags->status = 2;
		vars->flags->error = 1;
		return (ft_ret_null("Syntax error", 1));
	}
	return (str_1);
}

static char	**ft_get_com_2(int *num)
{
	char	**strk;

	if (!(strk = ft_calloc(*num + 1, sizeof(char*))))
		return (NULL);
	strk[*num] = NULL;
	return (strk);
}

static char	**ft_get_com_3(char **strk, char **str)
{
	free(*str);
	return (strk);
}

char		**ft_get_command(t_vars *vars, char *str, char a)
{
	t_temp_1	tp;

	if (!(str = ft_get_com_1(vars, str, a, &tp)))
		return (NULL);
	if (ft_start_get_com(vars, str, &tp) || !(tp.strk = ft_get_com_2(&tp.num)))
		return (NULL);
	while (++tp.i < tp.num && tp.k < (int)ft_strlen(str))
	{
		if (!(tp.strk[tp.i] = ft_strdup("")))
			return (NULL);
		ft_init_flags(vars);
		while (str[++tp.k])
		{
			if (ft_get_com_if_5(str, a, &tp) || ft_event(vars, str[tp.k]))
				continue;
			if (ft_get_com_if_2(vars) && ft_get_com_if_1(str, a, &tp))
				break ;
			(ft_get_3(vars, str, a, &tp)) ? ft_event(vars, str[++tp.k]) : 0;
			if (!(tp.strk[tp.i] = ft_strputend(tp.strk[tp.i], str[tp.k])))
				return (NULL);
		}
		if (ft_get_com_if_4(a, &tp))
			return (ft_get_com_syntax_err_2(vars));
	}
	return (ft_get_com_3(tp.strk, &str));
}
