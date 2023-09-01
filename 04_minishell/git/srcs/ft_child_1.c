/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:06:35 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 17:04:48 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function execute received command and exit
**	return (-2) - Success/Error
*/

#include "../minishell.h"

static int	ft_exec_path(t_vars *vars, int *k)
{
	int		ret;
	char	*prog;
	char	*prog_1;

	ret = execve(vars->args[0], vars->args, vars->envp);
	*k = -1;
	while (vars->path != NULL && vars->path[++*k] && ret == -1)
	{
		prog_1 = ft_strjoin(vars->path[*k], "/");
		prog = ft_strjoin(prog_1, vars->args[0]);
		free(prog_1);
		ret = execve(prog, vars->args, vars->envp);
		if (ret == 1)
		{
			ft_free_s(prog);
			ft_free_ss(vars->args);
			return (-2);
		}
		ft_free_s(prog);
	}
	return (ret);
}

static void	ft_not_found(t_vars *vars)
{
	char	*prog;

	prog = ft_strjoin(vars->args[0], ": command not found\n");
	write(1, prog, ft_strlen(prog));
	vars->flags->status = 127;
	ft_free_s(prog);
	return ;
}

static void	ft_signal_hand(t_vars *vars)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	tcsetattr(STDIN_FILENO, TCSANOW, &vars->termos->old);
}

int			ft_child_1(t_vars *vars)
{
	int		ret;
	int		k;

	ft_signal_hand(vars);
	if (vars->flags->fd[0])
	{
		if ((ret = close(vars->flags->fd[0])) == -1)
			return (ft_print(strerror(errno), -2));
		vars->flags->fd[0] = 0;
	}
	k = -1;
	while ((ret = vars->f[++k](vars, vars->args)) != 0)
	{
		if (ret < 0)
			return (ft_print(strerror(errno), -2));
		if (ret == 2)
			return (-2);
	}
	if ((ret = ft_exec_path(vars, &k)) == -2)
		return (-2);
	if ((vars->path == NULL && ret == -1) || (vars->path[k] && ret == -1))
		return (ft_print(strerror(errno), -2));
	if (!vars->path[k])
		ft_not_found(vars);
	return (-2);
}
