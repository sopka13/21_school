/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_com_if_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:07:40 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:19:48 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_get_com_if_2(t_vars *vars)
{
	if (vars->flags->squote == 0 && vars->flags->quote == 0 &&
		vars->flags->backslash == 0)
		return (1);
	return (0);
}
