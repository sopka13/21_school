/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:46:38 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 16:06:25 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUF 100000
# define STR "minishell $> "
# define FNAME_HIST "/minishell_hist"
# define UP "\e[A"
# define DOWN "\e[B"
# define RIGHT "\e[C"
# define LEFT "\e[D"
# define BACKSP 127
# define DEL "\e[3~"
# define ENTER 10

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>
# include <signal.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <limits.h>

typedef struct		s_flags
{
	int				squote;
	int				quote;
	int				backslash;
	int				and;
	int				std_out;
	int				error;
	int				status;
	int				fd_in;
	int				fd_out;
	int				save_stdin;
	int				save_stdout;
	int				fd[2];
	pid_t			last_pid;
	int				res_fd;
}					t_flags;

typedef struct		s_command
{
	char			**command;
	int				num;
}					t_com;

typedef struct		s_node
{
	char			*cmd;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_histdb
{
	size_t			size;
	t_node			*current;
	t_node			*head;
	t_node			*tail;
}					t_histdb;

typedef struct		s_tc
{
	char			*name;
	struct termios	new;
	struct termios	old;
	int				co;
	int				li;
	int				hist_fd;
	int				tmp_fd;
	t_histdb		*hist;
	int				inhist;
	int				acthist;
	char			*cmd;
	int				i;
}					t_tc;

typedef struct		s_vars
{
	char			str[BUF];
	int				argc;
	char			**argv;
	char			**envp;
	t_com			**com_l;
	char			**args;
	char			*home;
	char			**path;
	char			*pwd;
	t_flags			*flags;
	int				(*f[8])(struct s_vars*, char**);
	t_tc			*termos;
	pid_t			pid;
}					t_vars;

extern t_vars		*g_vars;

typedef struct		s_temp_1
{
	char			**strk;
	int				i;
	int				k;
	int				num;
}					t_temp_1;

typedef struct		s_temp_2
{
	int				ret;
	int				i;
	char			*line_out;
	char			*name_env;
	char			*env_var;
}					t_temp_2;

int					ft_atoi_exit_status(t_vars *vars, char *arg);
long long int		ft_atoi_spec(t_vars *vars, const char *arg);
int					ft_cd(t_vars *vars, char **args);
int					ft_change_env(t_vars *vars, char *env);
int					ft_check_strt(t_vars *vars, int const l, char **pipe_str);
int					ft_clean_vars(t_vars *vars);
int					ft_child_1(t_vars *vars);
int					ft_echo_arg_1(char *str, t_temp_2 *temp);
int					ft_echo_arg_2(t_temp_2 *temp);
int					ft_echo_arg_3(t_temp_2 *temp);
char				*ft_echo_arg_4(char *str, t_temp_2 *temp);
int					ft_echo_arg_5(t_vars *vars, char *str, t_temp_2 *temp);
int					ft_echo_arg_exep(t_vars *vars, char *str, t_temp_2 *temp);
int					ft_echo_arg_start(t_vars *vars, t_temp_2 *temp);
char				*ft_echo_arg(t_vars *vars, char *str);
int					ft_echo(t_vars *vars, char **args);
int					ft_env(t_vars *vars, char **args);
char				**ft_envp(char **envp);
int					ft_event(t_vars *vars, char a);
int					ft_exit_2(t_vars *vars, char **args);
void				ft_exit(t_vars *vars);
int					ft_export_in(t_vars *vars, char *str_1, char *str_2);
int					ft_export_s(t_vars *vars, char **args, char **name, int i);
int					ft_export(t_vars *vars, char **args);
int					ft_file_dc_s(t_vars *vars, char *str, char **line, int *i);
int					ft_file_desc(t_vars *vars, char *str);
void				ft_free_com_l(t_vars *vars);
void				ft_free_s(char *str);
void				ft_free_ss(char **str);
int					ft_get_com_if_1(const char *str, char a, t_temp_1 *temp);
int					ft_get_com_if_2(t_vars *vars);
int					ft_get_3(t_vars *vars, char *str, char a, t_temp_1 *temp);
int					ft_get_com_if_4(char a, t_temp_1 *temp);
int					ft_get_com_if_5(char *str, char a, t_temp_1 *temp);
int					ft_get_com_syntax_err_1(t_vars *vars);
char				**ft_get_com_syntax_err_2(t_vars *vars);
char				**ft_get_command(t_vars *vars, char *str, char a);
char				*ft_get_envp(t_vars *vars, char *str);
int					ft_get_result(t_vars *vars);
char				*ft_get_tilda(t_vars *vars, char *line_out);
char				*ft_get_var_value(char *env_var);
void				ft_init_flags(t_vars *vars);
void				ft_init_fd(t_vars *vars);
int					ft_if_have_equal(const char *str);
int					ft_if_have_tilda(t_vars *vars, char *str, int i);
void				ft_init_fd(t_vars *vars);
void				ft_init_flags(t_vars *vars);
int					ft_leigth_num(long long int num);
int					ft_new_line_error(char *str, char a);
int					ft_non_file(t_vars *vars);
char				*ft_not_equal(t_vars *vars, char *str, t_temp_2 *temp);
int					ft_num_if_1(t_vars *vars, char *str, char a, int i);
int					ft_num(t_vars *vars, char *str, char a);
int					ft_open_desc_1(t_vars *vars, int *i, char *str);
int					ft_open_desc_2(t_vars *vars, int *i, char *str);
int					ft_open_desc_3(t_vars *vars, int *i, char *str);
int					ft_open_desc_synerr(t_vars *vars);
int					ft_open_desc(t_vars *vars, int *i, char *str);
int					ft_only_space(char *str, int i);
int					ft_parse(t_vars *vars);
int					ft_pt_1(t_vars *vars, char **pipe_str, int num, pid_t pid);
int					ft_parent_2(t_vars *vars, char **pipe_str, int num);
int					ft_print(char *str, int a);
char				**ft_putendstr_arr(char **arr, char *str);
int					ft_pwd(t_vars *vars, char **args);
int					ft_read_input(t_tc *tmc, t_vars *vars);
char				**ft_realloc_arr(char **arr, int n, int size);
char				**ft_rem_elem_arr(char **arr, char const *str);
char				*ft_rem_quotes_1(t_vars *vars, char *str, int *k);
void				ft_rem_quotes_2(t_vars *vars, int *i, int *k);
char				*ft_rem_quotes_3(t_vars *vars, char *str, int *i, int *k);
void				ft_rem_quotes_4(t_vars *vars, char *str, int i);
int					ft_rem_quotes(t_vars *vars);
int					ft_repare_fd(t_vars *vars);
char				*ft_ret_null(char *str, int num);
void				ft_sigint(int status);
void				ft_signal(t_vars *vars);
int					ft_size_arr(char **arr);
int					ft_start_input(t_vars *vars);
int					ft_start_fork_exit_1(t_vars *vars, int ret);
int					ft_start_fork_exit_2(t_vars *vars);
int					ft_start_fork(t_vars *vars, char **pipe_str, int num);
int					ft_start_get_com(t_vars *vars, char *str, t_temp_1 *temp);
int					ft_start_input(t_vars *vars);
int					ft_stop(t_vars *vars, char **args);
int					ft_unset(t_vars *vars, char **args);
int					ft_valid_env_chr(char a);
char				**ft_valid_name_export_1(char **name);
int					ft_valid_name_export(t_vars *vars, char *str, char **name);
int					ft_write_and_ret(char *str_1, char *str_2, int ret);
int					put_int(int c);
void				upkey(t_tc *tmc);
int					append_cmd(t_vars *vars, t_tc *tmc);
void				bibip(void);
void				clear_eol(void);
void				clear_down(void);
int					pushback(t_histdb *list, char *cmd);
void				downkey(t_tc *tmc);
void				backspace(t_tc *tmc);
void				hist_wipe(t_tc *tmc);
void				print_symbol(char *buff, t_tc *tmc);
t_histdb			*create_histdb(void);
int					get_hist(t_vars *vars, t_tc *tmc);
int					tmc_prep(t_tc *tmc);
int					tmc_get(t_tc *tmc);
int					tmc_set(t_tc *tmc);
int					enterkey(t_tc *tmc, t_vars *vars);
void				ctrld(t_tc *tmc, t_vars *vars, char *buff);
int					got_cmd(t_tc *tmc, t_vars *vars);
void				prep_cmd(t_tc *tmc, t_vars *vars);
void				save_clear(void);
int					main(int argc, char **argv, char **envp);

#endif
