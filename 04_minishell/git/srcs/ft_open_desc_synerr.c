/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_desc_synerr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:49:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 00:10:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_open_desc_synerr(t_vars *vars)
{
	vars->flags->status = 2;
	return (ft_print("Syntax error", -1));
}
