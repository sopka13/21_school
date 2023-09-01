/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_if_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:52:48 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:53:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_num_if_1(t_vars *vars, char *str, char a, int i)
{
	if (vars->flags->squote == 0 && vars->flags->quote == 0 &&
		vars->flags->backslash == 0 && a != '&' && str[i] == a &&
		i != 0 && str[i - 1] != a && str[i] != '\0')
		return (1);
	return (0);
}
