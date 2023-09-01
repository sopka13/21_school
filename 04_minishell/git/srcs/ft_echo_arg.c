/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:44:46 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 18:01:05 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check args for equality env vars (change name var to value)
** 	return (str) - Success
** 	return (NULL) - Error
*/

#include "../minishell.h"

static int	ft_echo_arg_if_1(t_vars *vars, char *str, int i)
{
	if (str[i] == '$' && vars->flags->squote == 0 &&
		vars->flags->backslash == 0)
		return (1);
	return (0);
}

char		*ft_echo_arg(t_vars *vars, char *str)
{
	t_temp_2	temp;

	if (ft_echo_arg_start(vars, &temp))
		return (NULL);
	while (str[++temp.i])
	{
		ft_event(vars, str[temp.i]);
		if (ft_echo_arg_if_1(vars, str, temp.i))
		{
			if ((temp.ret = ft_echo_arg_5(vars, str, &temp)) == 1)
				continue;
			if (temp.ret == -1)
				return (NULL);
		}
		else if (ft_if_have_tilda(vars, str, temp.i))
		{
			if (!(temp.line_out = ft_get_tilda(vars, temp.line_out)))
				return (NULL);
		}
		else if (!(temp.line_out = ft_not_equal(vars, str, &temp)))
			return (NULL);
	}
	return (ft_echo_arg_4(str, &temp));
}
