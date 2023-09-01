#ifndef EXAM_H
# define EXAM_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include <stdio.h>

# define ERRFATAL "error: fatal\n"
# define ERREXEC "error: cannot execute "
# define ERRCD "error: cd: cannot change directory to "

typedef struct	s_pipe
{
	char		**argv;
}				t_pipe;

typedef struct	s_dot
{
	char		**argv;
	t_pipe		**pipe_s;
}				t_dot;

typedef struct	s_vars
{
	int			argc;
	char		**argv;
	char		**envp;
	t_dot		**dot_s;
	pid_t		pid;
	pid_t		last_pid;
	int			fd[2];
	int			save_stdin;
	int			save_stdout;
	int			exit_status;
}				t_vars;

extern t_vars	*vars;

void		ft_start_fork(t_dot *dot_s, int n);

#endif