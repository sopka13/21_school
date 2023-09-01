/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:56:24 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 22:56:27 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_init_flags(t_vars *vars)
{
	vars->flags->squote = 0;
	vars->flags->quote = 0;
	vars->flags->backslash = 0;
	vars->flags->and = 0;
	vars->flags->std_out = 0;
	vars->flags->error = 0;
	vars->flags->fd_in = 0;
	vars->flags->fd_out = 0;
}
