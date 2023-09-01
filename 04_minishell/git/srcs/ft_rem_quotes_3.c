/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_quotes_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:12:56 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:57:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_rem_quotes_3(t_vars *vars, char *str, int *i, int *k)
{
	if (vars->flags->backslash == 1 && (vars->args[*i][*k + 1] == '\'' ||
		vars->args[*i][*k + 1] == '\"'))
	{
		ft_event(vars, vars->args[*i][*k]);
		*k += 1;
	}
	if (!(str = ft_strputend(str, vars->args[*i][*k])))
		return (ft_ret_null(strerror(errno), -2));
	return (str);
}
