# include "exam.h"

t_vars	*vars;

void	ft_bzero(void *arr, size_t size)
{
	char	*p;

	p = (char*)arr;
	while (--size)
		p[size] = '\0';
	p[size] = '\0';
	return ;
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

void		ft_exit(int ret)
{
	int		i;
	int		k;
	int		l;

	i = -1;
	while (vars->dot_s && vars->dot_s[++i])
	{
		k = -1;
		while (vars->dot_s[i]->argv && vars->dot_s[i]->argv[++k])
		{
			// write(2, vars->dot_s[i]->argv[k], ft_strlen(vars->dot_s[i]->argv[k]));
			free(vars->dot_s[i]->argv[k]);
		}
		free(vars->dot_s[i]->argv);
		k = -1;
		while (vars->dot_s[i]->pipe_s && vars->dot_s[i]->pipe_s[++k])
		{
			l = -1;
			while (vars->dot_s[i]->pipe_s[k]->argv && vars->dot_s[i]->pipe_s[k]->argv[++l])
			{
				free(vars->dot_s[i]->pipe_s[k]->argv[l]);
			}
			free(vars->dot_s[i]->pipe_s[k]->argv);
			free(vars->dot_s[i]->pipe_s[k]);
		}
		free(vars->dot_s[i]->pipe_s);
		free(vars->dot_s[i]);
	}
	free(vars->dot_s);
	if (ret == 0)
	{
		// write(2, "Fine\n", 6);
		exit (0);
	}
	exit(vars->exit_status);
}

int			ft_print_error(char *str)
{
	write(2, str, ft_strlen(str));
	vars->exit_status = -1;
	return (vars->exit_status);
}

int			ft_size_arr_char(char **arr)
{
	int		i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int			ft_size_arr_dot(t_dot **dot_s)
{
	int		i;

	if (!dot_s)
		return (0);
	i = 0;
	while(dot_s[i])
		i++;
	return (i);
}

t_dot		**ft_add_new_dot(t_dot **dot_s)
{
	int		size;
	t_dot	**new;
	int		i;

	// write(2, "ft_add_new_dot start\n", 22);
	//	step 1: allocate memory
	size = ft_size_arr_dot(dot_s);
	if (!(new = (t_dot**)malloc(sizeof(t_dot*) * (size + 2))))
		ft_exit(ft_print_error(ERRFATAL));
	new[size + 1] = NULL;
	// write(2, "ft_add_new_dot step 1 ok\n", 26);

	//	step 2: rewrite data
	i = -1;
	while (++i < size)
		new[i] = dot_s[i];
	if (!(new[i] = (t_dot*)malloc(sizeof(t_dot))))
		ft_exit(ft_print_error(ERRFATAL));
	ft_bzero(new[i], sizeof(t_dot));
	// write(2, "ft_add_new_dot step 2 ok\n", 26);

	// step 3: free memory
	if (size)
		free(dot_s);
	// write(2, "ft_add_new_dot step 3 ok\n", 26);
	return (new);
}

char		*ft_strdup(char *str)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return(NULL);
	new[ft_strlen(str)] = '\0';
	i = -1;
	while (str[++i])
		new[i] = str[i];
	return (new);
}

char		**ft_add_str_in_arr(char **arr, char *str)
{
	int		size;
	char	**new;
	int		i;

	// write(2, "ft_add_str_in_arr start\n", 25);
	// printf("Write received arr str = %s\n", str);
	// int	z = -1;
	// while (arr && arr[++z])
	// 	printf("i = %d arr[i] = %s\n", z, arr[z]);

	//	step 1: allocate memory
	size = ft_size_arr_char(arr);
	if (!(new = (char**)malloc(sizeof(char*) * (size + 2))))
		ft_exit(ft_print_error(ERRFATAL));
	new[size + 1] = NULL;
	// write(2, "ft_add_str_in_arr step 1 ok\n", 29);
	// printf("ft_add_str_in_arr step 1 ok size = %d\n", size);

	//	step 2: rewrite data
	i = -1;
	while (++i < size)
		new[i] = arr[i];
	if (!(new[i] = ft_strdup(str)))
		ft_exit(ft_print_error(ERRFATAL));
	// if (!(new[i] = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	// 	ft_exit(ft_print_error(ERRFATAL));
	// new[i][ft_strlen(str)] = '\0';
	// write(2, "ft_add_str_in_arr step 2 ok\n", 29);
	// printf("ft_add_str_in_arr step 2 ok return ft_strdup = %s\n", new[i]);

	//	step 3: free old arr
	if (size)
		free(arr);
	// write(2, "ft_add_str_in_arr step 3 ok\n", 29);
	return (new);
}

int			ft_size_arr_pipe(t_pipe **pipe_s)
{
	int		i;

	i = 0;
	if (!pipe_s)
		return (0);
	while (pipe_s[i])
		i++;
	return (i);
}

t_pipe		**ft_add_new_pipe(t_pipe **pipe_s)
{
	int		size;
	t_pipe	**new;
	int		i;

	//	step 1: get size pipe_s
	size = ft_size_arr_pipe(pipe_s);
	// printf("ft_size_arr_pipe start size = %d\n", size);

	//	step 2: allocate memory
	if (!(new = (t_pipe**)malloc(sizeof(t_pipe*) * (size + 2))))
		ft_exit(ft_print_error(ERRFATAL));
	new[size + 1] = NULL;
	// printf("ft_size_arr_pipe step 2 ok\n");

	//	step 3: rewrite data
	i = -1;
	while (++i < size)
		new[i] = pipe_s[i];
	if (!(new[i] = (t_pipe*)malloc(sizeof(t_pipe))))
		ft_exit(ft_print_error(ERRFATAL));
	// printf("ft_size_arr_pipe step 3 ok\n");

	//	step 4: free memory
	if (size)
		free(pipe_s);
	// printf("ft_size_arr_pipe step 4 ok\n");
	return (new);
}

void		ft_parser(void)
{
	int		i;
	int		k;
	int		l;

	i = 1;
	k = -1;
	while(vars->argv[i])
	{
		// write(2, "ft_parser start\n", 17);
		// printf("ft_parser start i = %d argv[i] = %s\n", i, vars->argv[i]);
		//	step 1: skip first ";"
		while (vars->argv[i] && (!(strcmp(vars->argv[i], ";"))))// || !(strcmp(vars->argv[i], "|")))))
			i++;
		// write(2, "ft_parser step 1 ok\n", 21);
		// printf("ft_parser step 1 ok argv[i]= %s\n", vars->argv[i]);

		//	step 2: check if dont have args
		if (i == vars->argc)
			ft_exit(0);
		// write(2, "ft_parser step 2 ok\n", 21);

		//	step 3: add new t_dot struct
		vars->dot_s = ft_add_new_dot(vars->dot_s);
		// write(2, "ft_parser step 3 ok\n", 21);
		// printf("ft_parser step 3 ok k = %d\n", k);

		//	step 4: add args in array
		k++;
		while (vars->argv[i] && strcmp(vars->argv[i], ";"))
		{
			// printf("ft_parser step 4 cycle start\n");
			vars->dot_s[k]->argv = ft_add_str_in_arr(vars->dot_s[k]->argv, vars->argv[i]);

			// int q = -1;
			// while (vars->dot_s[k]->argv[++q])
			// 	printf("i = %d elem i = %s\n", q, vars->dot_s[k]->argv[q]);

			i++;
		}
		// write(2, "ft_parser step 4 ok\n", 21);
		// printf("ft_parser step 4 ok k = %d argv[0] = %s\n", k, vars->dot_s[k]->argv[0]);
	}
	
	i = 0;
	while (vars->dot_s[i])		//every t_dot struct
	{
		k = 0;
		l = -1;
		while (vars->dot_s[i]->argv && vars->dot_s[i]->argv[k]) //every args in t_dot struct
		{
			while (vars->dot_s[i]->argv[k] && !(strcmp(vars->dot_s[i]->argv[k], "|")))
				k++;

			//	step 0: if no more args
			if (!vars->dot_s[i]->argv[k])
				continue ;

			//	step 1: create t_pipe struct
			vars->dot_s[i]->pipe_s = ft_add_new_pipe(vars->dot_s[i]->pipe_s);
			l++;

			//	step 2: add arg in arr
			while (vars->dot_s[i]->argv[k] && strcmp(vars->dot_s[i]->argv[k], "|"))
			{
				vars->dot_s[i]->pipe_s[l]->argv = ft_add_str_in_arr(vars->dot_s[i]->pipe_s[l]->argv, vars->dot_s[i]->argv[k]);
				k++;
			}
			// printf("i = %d arg = %s\n", k, vars->dot_s[i]->argv[k]);
		}
		i++;
	}

	// printf("Write received arguments\n");
	// int z = -1;
	// int q;
	// while(vars->dot_s && vars->dot_s[++z])
	// {
	// 	q = -1;
	// 	while (vars->dot_s[z]->argv[++q])
	// 		printf("z = %d q = %d arg = %s\n", z, q, vars->dot_s[z]->argv[q]);
	// }

	// printf("Write received arguments in pipes\n");
	// z = -1;
	// int	m;
	// while(vars->dot_s && vars->dot_s[++z])
	// {
	// 	q = -1;
	// 	while (vars->dot_s[z]->pipe_s && vars->dot_s[z]->pipe_s[++q])
	// 	{
	// 		m = -1;
	// 		while (vars->dot_s[z]->pipe_s[q]->argv && vars->dot_s[z]->pipe_s[q]->argv[++m])
	// 			printf("z = %d q = %d m = %d args[i] = %s\n", z, q, m, vars->dot_s[z]->pipe_s[q]->argv[m]);
	// 	}
	// }
	return ;
}

void		ft_valid_args(void)
{
	int		i;
	if (vars->argc <= 1)
		ft_exit(0);
	
	i = 1;
	while (vars->argv[i] && (!(strcmp(vars->argv[i], ";")) || !(strcmp(vars->argv[i], "|"))))
		i++;
	if (i == vars->argc)
		ft_exit(0);
	return ;
}

void		ft_cd(char **args)
{
	int		ret;

	// printf("ft_cd start argv[0] = %s argv[1] = %s\n", args[0], args[1]);
	ret = chdir(args[1]);
	if (ret < 0)
	{
		ft_print_error(ERRCD);
		ft_print_error(args[1]);
		ft_print_error("\n");
	}
	return ;
}

void		ft_init_fd(void)
{
	vars->save_stdin = dup(0);
	vars->save_stdout = dup(1);
}

void		ft_repare_fd(void)
{
	dup2(vars->save_stdin, 0);
	dup2(vars->save_stdout, 1);
	close(vars->save_stdin);
	close(vars->save_stdout);
}

void		ft_child(t_dot *dot_s, int n)
{
	int		ret;

	close(vars->fd[0]);

	ret = execve(dot_s->pipe_s[n]->argv[0], dot_s->pipe_s[n]->argv, vars->envp);
	if (ret < 0)
	{
		ft_print_error(ERREXEC);
		ft_print_error(dot_s->pipe_s[n]->argv[0]);
		close(vars->fd[1]);
		ft_exit(ft_print_error("\n"));
	}
	else
	{
		close(vars->fd[1]);
		ft_exit(0);
	}
}

void		ft_parent(t_dot *dot_s, int n)
{
	pid_t	pid;

	close(vars->fd[1]);
	pid = vars->pid;
	vars->last_pid = vars->pid;
	if (dot_s->pipe_s[n] && dot_s->pipe_s[n + 1])
	{
		dup2(vars->fd[0], 0);
		close(vars->fd[0]);
		ft_start_fork(dot_s, n + 1);
	}
	if (vars->last_pid != 0)
	{
		waitpid(vars->last_pid, &vars->exit_status, 0);
		vars->last_pid = 0;
		ft_repare_fd();
		return ;
	}
	else
	{
		kill(pid, SIGINT);
		waitpid(pid, NULL, 0);
	}
	return ;
}

void		ft_start_fork(t_dot *dot_s, int n)
{
	//	step 0: if have cd command
	if (!(strcmp(dot_s->pipe_s[0]->argv[0], "cd")))
	{
		ft_cd(dot_s->pipe_s[0]->argv);
		return ;
	}

	// step 1: save std desc
	if (n == 0)
		ft_init_fd();
	
	//	step 2: create pipe and change desc
	if (dot_s->pipe_s[n] && dot_s->pipe_s[n + 1])
	{
		pipe(vars->fd);
		dup2(vars->fd[1], 1);
		close(vars->fd[1]);
	}

	if (dot_s->pipe_s[n] && !dot_s->pipe_s[n + 1])
	{
		dup2(vars->save_stdout, 1);
		close(vars->save_stdout);
	}
	
	//	step 3: execute system command
	vars->pid = fork();
	if (vars->pid == 0)
		ft_child(dot_s, n);
	else if (vars->pid > 0)
		ft_parent(dot_s, n);
	else
		ft_exit(ft_print_error(ERRFATAL));
}

void		ft_exec(void)
{
	int		i;

	i = -1;
	while (vars->dot_s && vars->dot_s[++i])				// every t_dot struct
	{
		ft_start_fork(vars->dot_s[i], 0);
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_vars	p;

	ft_bzero(&p, sizeof(p));
	vars = &p;
	vars->argc = argc;
	vars->argv = argv;
	vars->envp = envp;
	//	step 1: check valid number args
	ft_valid_args();
	//	step 2: start parser
	ft_parser();
	ft_exec();
	// while (1);
	ft_exit(0);
	return (0);
}