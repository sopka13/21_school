/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:42:40 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 17:05:03 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Programm name: minishell
** External functs:
** 	printf, malloc, free, write, open, read, close, fork, wait,
** 	waitpid, wait3, wait4, signal, kill, exit, getcwd, chdir,
** 	stat, lstat, fstat, execve, dup, dup2, pipe, opendir, readdir,
** 	closedir, strerror, errno, isatty, ttyname, ttyslot, ioctl,
** 	getenv, tcsetattr, tcgetattr, tgetent, tgetflag,tgetnum,
** 	tgetstr, tgoto, tputs
** 1.	Not use more than one global variable, think about it and be ready to
** 		explain why you do it.
** 2.	Show a prompt when waiting for a new command
** 3.	Search and launch the right executable (based on the PATH variable or
** 		by usingrelative or absolute path) like in bash
** 4.	It must implement the builtins like in bash:
** 		- echo with option ’-n’
** 		- cd with only a relative or absolute path
** 		- pwd without any options
** 		- export without any options
** 		- unset without any options
** 		- env without any options and any arguments
** 		- exit without any options
** 5.	; in the command should separate commands like in bash
** 6.	’ and " should work like in bash except for multiline commands
** 7.	Redirections < >“>>” should work like in bash except for file
** 		descriptor aggregation
** 8.	Pipes | should work like in bash
** 9.	Environment variables ($ followed by characters) should work
** 		like in bash
** 10.	$? should work like in bash
** 11.	ctrl-C, ctrl-D and ctrl-\ should have the same result as in bash
** 12.	Use up and down arrows to navigate through the command using termcap
** 		(mandatory) history which we will then be able to edit (at least like
** 		we can for classic lines) if we feel like it (the line,
** 		not the history).
*/

#include "../minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

t_vars		*g_vars;

static int	ft_start_main(t_vars *vars)
{
	char	*name;
	char	*name_1;

	vars->flags->status = 0;
	vars->f[0] = ft_echo;
	vars->f[1] = ft_cd;
	vars->f[2] = ft_pwd;
	vars->f[3] = ft_export;
	vars->f[4] = ft_unset;
	vars->f[5] = ft_env;
	vars->f[6] = ft_exit_2;
	vars->f[7] = ft_stop;
	return (0);
}

void		ft_sigint(int status)
{
	int		ret;

	ft_bzero(g_vars->termos->cmd, BUF);
	g_vars->termos->i = 0;
	if (g_vars->flags->last_pid == 0)
	{
		write(1, "^C\n", 4);
		write(1, STR, ft_strlen(STR));
	}
	else
		write(1, "\n", 2);
	tputs(save_cursor, 1, put_int);
}

void		ft_signal(t_vars *vars)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sigint);
}

int			main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	t_flags	flags;
	t_tc	tmc;
	int		ret;

	g_vars = &vars;
	ft_bzero(&vars, sizeof(vars));
	vars.argc = argc;
	vars.argv = argv;
	vars.flags = &flags;
	vars.termos = &tmc;
	if (!(vars.envp = ft_envp(envp)) || ft_start_main(&vars) ||
		tmc_prep(&tmc) || get_hist(&vars, &tmc))
		return (1);
	ft_signal(&vars);
	while (1)
	{
		if (ft_start_input(&vars))
			ft_exit(&vars);
		if ((ret = ft_read_input(&tmc, &vars)) != 0)
			if (ret == -1 || ft_parse(&vars) || ((ret = isatty(0)) == 1 &&
			(ret = tcsetattr(STDIN_FILENO, TCSANOW, &vars.termos->new)) == -1))
				ft_exit(&vars);
	}
	return (0);
}
