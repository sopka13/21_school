/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:39:48 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:03:02 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function emulate philosophers actions
*/

#include "philo.h"

static int	ft_philo_loop_body(t_vars *vars, int number_philo, long int *time)
{
	pthread_mutex_lock(&vars->forks[vars->philos[number_philo]->fork_2]);
	pthread_mutex_lock(&vars->forks[vars->philos[number_philo]->fork_1]);
	if (vars->end || ft_if_die(vars, number_philo, time))
	{
		pthread_mutex_unlock(&vars->forks[vars->philos[number_philo]->fork_2]);
		pthread_mutex_unlock(&vars->forks[vars->philos[number_philo]->fork_1]);
		return (-1);
	}
	ft_print_status(vars, number_philo + 1, STATUS_TAKE_F);
	ft_print_status(vars, number_philo + 1, STATUS_EAT);
	usleep(vars->time_to_eat * 1000);
	time[0] = vars->time.tv_sec;
	time[1] = vars->time.tv_usec;
	pthread_mutex_unlock(&vars->forks[vars->philos[number_philo]->fork_1]);
	pthread_mutex_unlock(&vars->forks[vars->philos[number_philo]->fork_2]);
	ft_print_status(vars, number_philo + 1, STATUS_SLEEP);
	usleep(vars->time_to_sleep * 1000);
	ft_print_status(vars, number_philo + 1, STATUS_THINK);
	return (0);
}

static int	ft_philo_cycle(t_vars *vars, int number_philo, long int *time)
{
	int		number_eat;
	int		k;

	k = 0;
	number_eat = vars->number_eat;
	if (number_eat)
		k = 1;
	else
		number_eat = 1;
	while (number_eat)
	{
		if (ft_philo_loop_body(vars, number_philo, time))
			return (-1);
		number_eat = number_eat - k;
	}
	return (0);
}

void	*ft_philo(void *args)
{
	t_vars		*vars;
	int			number_philo;
	long int	time[2];

	memset(time, '\0', sizeof(time));
	vars = (t_vars *)args;
	number_philo = ft_number_philo(vars);
	ft_philo_cycle(vars, number_philo, time);
	return (NULL);
}
