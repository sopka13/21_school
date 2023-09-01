/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_com_syntax_err_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:37:09 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 00:10:50 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_get_com_syntax_err_2(t_vars *vars)
{
	ft_print("Syntax error", 1);
	vars->flags->status = 2;
	vars->flags->error = 1;
	return (NULL);
}
