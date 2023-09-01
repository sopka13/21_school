/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:51:36 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:03:01 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_time(t_vars *vars)
{
	gettimeofday(&vars->time, NULL);
	vars->valid_time = (vars->time.tv_usec / 1000 + vars->time.tv_sec * 1000)
		 - vars->start_time;
}

void	ft_print_status(t_vars *vars, int number, int status)
{
	ft_time(vars);
	pthread_mutex_lock(vars->print_mutex);
	if (vars->end)
		;
	else if (status == 0)
		printf("%ld %d has taken a fork\n", vars->valid_time, number);
	else if (status == 1)
		printf("%ld %d is eating\n", vars->valid_time, number);
	else if (status == 2)
		printf("%ld %d is sleeping\n", vars->valid_time, number);
	else if (status == 3)
		printf("%ld %d is thinking\n", vars->valid_time, number);
	else if (status == 4)
	{
		printf("%ld %d died\n", vars->valid_time, number);
		vars->end = 1;
	}
	pthread_mutex_unlock(vars->print_mutex);
	return ;
}
