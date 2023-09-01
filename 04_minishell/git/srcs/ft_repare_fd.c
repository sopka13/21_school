/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repare_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:25:21 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 22:25:25 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Repare std descriptors
** 	return (-2) - Error
** 	return (0) - Success
*/

#include "../minishell.h"

int			ft_repare_fd(t_vars *vars)
{
	int		ret;

	if ((vars->flags->save_stdin != 0 &&
		(ret = dup2(vars->flags->save_stdin, 0)) == -1) ||
		(vars->flags->save_stdout != 0 &&
		(ret = dup2(vars->flags->save_stdout, 1)) == -1))
		return (ft_print(strerror(errno), -2));
	vars->flags->save_stdin = 0;
	vars->flags->save_stdout = 0;
	if (vars->flags->fd[0])
	{
		close(vars->flags->fd[0]);
		vars->flags->fd[0] = 0;
	}
	if (vars->flags->fd[1])
	{
		close(vars->flags->fd[1]);
		vars->flags->fd[1] = 0;
	}
	return (0);
}
