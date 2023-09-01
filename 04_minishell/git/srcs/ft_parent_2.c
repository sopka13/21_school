/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:30:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:04:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function start if have our command function
** 	return (0) - Success
** 	return (-1/-2) - Error
*/

#include "../minishell.h"

int			ft_parent_2(t_vars *vars, char **pipe_str, int num)
{
	int		ret;

	if (vars->flags->fd[1])
	{
		if ((ret = close(vars->flags->fd[1])) == -1)
			return (ft_print(strerror(errno), -2));
		vars->flags->fd[1] = 0;
	}
	if (pipe_str[++num])
	{
		if (vars->flags->std_out != 1 && (ret = dup2(vars->flags->fd[0], 0)))
			return (ft_print(strerror(errno), -2));
		vars->flags->std_out = 0;
		if ((ret = ft_start_fork(vars, pipe_str, num)) < 0)
			return (ret);
	}
	else if ((ret = ft_repare_fd(vars)) == -2)
		return (ret);
	return (0);
}
