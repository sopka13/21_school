/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:39:48 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:24:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function emulate philosophers actions
*/

#include "philo_bonus.h"

static int	ft_philo_mutex(t_vars *vars, int number_philo, long int *time)
{
	return (0);
}

static int	ft_philo_loop_body(t_vars *vars, int number_philo, long int *time)
{
	if (vars->end || ft_if_die(vars, number_philo, time))
		return (1);
	sem_wait(vars->sema);
	sem_wait(vars->sema);
	ft_print_status(vars, number_philo + 1, STATUS_TAKE_F);
	ft_print_status(vars, number_philo + 1, STATUS_EAT);
	usleep(vars->time_to_eat * 1000);
	sem_post(vars->sema);
	sem_post(vars->sema);
	time[0] = vars->time.tv_sec;
	time[1] = vars->time.tv_usec;
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
			return (1);
		number_eat = number_eat - k;
	}
	return (2);
}

int	ft_philo(t_vars *vars, int i)
{
	int			number_philo;
	long int	time[2];

	memset(time, '\0', sizeof(time));
	number_philo = vars->philos[i]->number;
	if (ft_philo_cycle(vars, number_philo, time))
		return (1);
	return (0);
}
