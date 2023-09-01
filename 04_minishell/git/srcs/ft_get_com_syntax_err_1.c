/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_com_syntax_err_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:34:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 00:10:49 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_get_com_syntax_err_1(t_vars *vars)
{
	vars->flags->error = 1;
	vars->flags->status = 2;
	return (ft_print("Syntax error", 1));
}
