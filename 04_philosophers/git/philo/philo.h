/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:57:41 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:03:03 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define STATUS_TAKE_F 0
# define STATUS_EAT 1
# define STATUS_SLEEP 2
# define STATUS_THINK 3
# define STATUS_DIE 4

typedef struct s_philo
{
	int				fork_1;
	int				fork_2;
	pthread_t		pthread;
}					t_philo;

typedef struct s_vars
{
	int				number_get;
	struct timeval	time;
	int				number_p;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long int		valid_time;
	long int		start_time;
	int				number_eat;
	int				*retval;
	t_philo			**philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*number_get_mutex;
	pthread_mutex_t	*global_mutex;
	pthread_mutex_t	*print_mutex;
	int				end;
}					t_vars;

int		main(int argc, char **argv);
void	ft_print_status(t_vars *vars, int number, int status);
int		ft_get_args(int argc, char **argv, t_vars *vars);
int		ft_atoi(const char *a);
int		ft_print(char *str, int ret);
size_t	ft_strlen(const char *s);
void	*ft_philo(void *args);
char	*ft_itoa(int n);
int		ft_number_philo(t_vars *vars);
int		ft_wait_pthread(t_vars *vars);
int		ft_create_pthread(t_vars *vars);
void	ft_free(t_vars *vars);
int		ft_create_mutex(t_vars *vars);
int		ft_if_die(t_vars *vars, int number_philo, long int *time);

#endif
