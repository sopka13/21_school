/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 04:06:33 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:33:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <wait.h>
# include <signal.h>
# include <sys/fcntl.h>
# include <sys/stat.h>

# define STATUS_TAKE_F 0
# define STATUS_EAT 1
# define STATUS_SLEEP 2
# define STATUS_THINK 3
# define STATUS_DIE 4
# define SEM_NAME_1 "forks"
# define SEM_NAME_2 "print"

typedef struct s_philo
{
	int				number;
	pid_t			philos;
}					t_philo;

typedef struct s_vars
{
	int				number_p;
	int				number_get;
	struct timeval	time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long int		valid_time;
	long int		start_time;
	int				number_eat;
	int				*retval;
	t_philo			**philos;
	sem_t			*sema;
	sem_t			*sema_p;
	int				end;
}					t_vars;

int		main(int argc, char **argv);
void	ft_print_status(t_vars *vars, int number, int status);
int		ft_get_args(int argc, char **argv, t_vars *vars);
int		ft_atoi(const char *a);
size_t	ft_strlen(const char *s);
int		ft_philo(t_vars *vars, int i);
int		ft_print(char *str, int ret);
char	*ft_itoa(int n);
int		ft_number_philo(t_vars *vars);
int		ft_wait_forks(t_vars *vars);
int		ft_create_forks(t_vars *vars);
int		ft_exit(t_vars *vars, int status);
int		ft_create_semaphore(t_vars *vars);
int		ft_if_die(t_vars *vars, int number_philo, long int *time);

#endif