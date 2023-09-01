/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:56:36 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 22:56:38 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_init_fd(t_vars *vars)
{
	vars->flags->save_stdin = 0;
	vars->flags->save_stdout = 0;
	vars->flags->fd[0] = 0;
	vars->flags->fd[1] = 0;
	vars->flags->res_fd = 0;
}
