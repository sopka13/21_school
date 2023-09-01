/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_if_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:07:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:51:59 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_get_3(t_vars *vars, char *str, char a, t_temp_1 *tp)
{
	if (vars->flags->backslash == 1 && vars->flags->squote == 0 &&
		vars->flags->quote == 0 && tp->k + 1 < (int)ft_strlen(str) &&
		(((str[tp->k + 1] == a && a != '&') ||
		(a == ' ' && (str[tp->k + 1] == a ||
		str[tp->k + 1] == '\t'))) || (a == '&' && str[tp->k + 1] == '&' &&
		tp->k + 1 + 1 < (int)ft_strlen(str) && str[tp->k + 1 + 1] == '&')))
		return (1);
	return (0);
}
