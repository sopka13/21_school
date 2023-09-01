/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:19:59 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 17:01:33 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function run child process for execute command
** 	return (-1/-2) - Error
** 	return (0) - Success
*/

#include "../minishell.h"

static int	ft_start_fork_crt_chld(t_vars *vars, char **pipe_str, int num)
{
	int		ret;

	vars->pid = fork();
	if (vars->pid == 0 && (ret = ft_child_1(vars)) == -2)
	{
		vars->flags->last_pid = 0;
		return (ft_start_fork_exit_1(vars, ret));
	}
	else if (vars->pid > 0)
	{
		vars->flags->last_pid = vars->pid;
		if ((ret = ft_pt_1(vars, pipe_str, num, vars->pid)) < 0)
			return (ft_start_fork_exit_1(vars, ret));
	}
	else
		return (ft_start_fork_exit_2(vars));
	return (0);
}

static int	ft_start_fork_if_1(t_vars *vars)
{
	if (ft_strlen(vars->args[0]) != 0 &&
		(!ft_strcmp(vars->args[0], "cd") ||
		!ft_strcmp(vars->args[0], "unset") ||
		!ft_strcmp(vars->args[0], "exit") ||
		!ft_strcmp(vars->args[0], "export")))
		return (1);
	return (0);
}

static int	ft_start_fork_check_my_f(t_vars *vars, char **pipe_str, int num)
{
	int		k;
	int		ret;

	k = -1;
	while ((ret = vars->f[++k](vars, vars->args)) != 0)
	{
		if (ret < 0)
			if ((ret = ft_repare_fd(vars)) == -2)
				return (ret);
		if (ret == 2)
		{
			vars->flags->last_pid = 0;
			if ((ret = ft_parent_2(vars, pipe_str, num)) < 0)
			{
				if (ft_repare_fd(vars) == -2)
					return (-2);
				return (ret);
			}
		}
	}
	return (0);
}

int			ft_start_fork(t_vars *vars, char **pipe_str, int num)
{
	int		ret;

	if (num == 0)
		ft_init_fd(vars);
	if (num == 0 && ((vars->flags->save_stdin = dup(0)) == -1 ||
		(vars->flags->save_stdout = dup(1)) == -1))
		return (ft_print(strerror(errno), -2));
	if (pipe_str[num + 1] && (ret = pipe(vars->flags->fd)) != 0)
		return (ft_print(strerror(errno), -2));
	if (!pipe_str[num + 1] && num != 0 &&
		((ret = dup2(vars->flags->save_stdout, 1)) == -1 ||
		(vars->flags->save_stdout = dup(1)) == -1))
		return (ft_start_fork_exit_2(vars));
	if ((ret = ft_check_strt(vars, num, pipe_str)) < 0)
		return (ft_start_fork_exit_1(vars, ret));
	if (ft_start_fork_if_1(vars))
	{
		if ((ret = ft_start_fork_check_my_f(vars, pipe_str, num)) != 0)
			return (ret);
	}
	else if ((ret = ft_start_fork_crt_chld(vars, pipe_str, num)) != 0)
		return (ret);
	return (0);
}
