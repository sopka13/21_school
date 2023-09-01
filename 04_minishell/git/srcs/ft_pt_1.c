/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pt_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:32:22 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 13:15:50 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This functon start after create child process, track chil process
** 	and run next commands in conveyor
** 	return (0) - Success
** 	return (-1/-2) - Error
*/

#include "../minishell.h"

static int	ft_parent_1_close_fd(t_vars *vars)
{
	int		ret;

	if ((ret = close(vars->flags->fd[1])) == -1)
		return (ft_print(strerror(errno), -2));
	vars->flags->fd[1] = 0;
	return (0);
}

static int	ft_parent_1_strt(t_vars *vars, char **pipe_str, int num)
{
	int		ret;

	if (vars->flags->std_out != 1 && (ret = dup2(vars->flags->fd[0], 0)))
		return (ft_print(strerror(errno), -2));
	vars->flags->std_out = 0;
	if ((ret = ft_start_fork(vars, pipe_str, num)) < 0)
		return (ret);
	return (0);
}

static void	ft_parent_1_kill_proc(pid_t pid)
{
	kill(pid, SIGINT);
	waitpid(pid, NULL, 0);
}

int			ft_pt_1(t_vars *vars, char **pipe_str, int num, pid_t pid)
{
	int		ret;

	if (vars->flags->fd[1] && (ret = ft_parent_1_close_fd(vars)) != 0)
		return (ret);
	if (pipe_str[++num] && (ret = ft_parent_1_strt(vars, pipe_str, num)) != 0)
		return (ret);
	if (vars->flags->last_pid != 0)
	{
		ret = 0;
		if ((ret = waitpid(vars->flags->last_pid, &vars->flags->status, 0)) ==
		-1 || (vars->flags->status == 131 && ft_print("Quit core dumped", 0)))
			return (ft_print(strerror(errno), -2));
		vars->flags->last_pid = 0;
		if ((ret = ft_repare_fd(vars)) == -2)
			return (ret);
		if (vars->flags->status > 255)
		{
			vars->flags->status = vars->flags->status / 256;
			return (0);
		}
		return (0);
	}
	if ((ret = waitpid(pid, NULL, WNOHANG)) >= 0)
		ft_parent_1_kill_proc(pid);
	return (0);
}
