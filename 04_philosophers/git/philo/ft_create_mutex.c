/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:37:07 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:08:19 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function create mutex
*/

#include "philo.h"

static int	ft_create_mutex_global(t_vars *vars)
{
	vars->global_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (vars->global_mutex != NULL)
	{
		if ((pthread_mutex_init(vars->global_mutex, NULL)) != 0)
		{
			free(vars->global_mutex);
			return (-1);
		}
	}
	else
		return (-1);
	vars->print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (vars->print_mutex != NULL)
	{
		if ((pthread_mutex_init(vars->print_mutex, NULL)) != 0)
		{
			free(vars->print_mutex);
			return (-1);
		}
	}
	else
		return (-1);
	return (0);
}

static int	ft_create_mutex_number(t_vars *vars)
{
	vars->number_get_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (vars->number_get_mutex != NULL)
	{
		if ((pthread_mutex_init(vars->number_get_mutex, NULL)) != 0)
		{
			free(vars->number_get_mutex);
			return (-1);
		}
	}
	else
		return (-1);
	return (0);
}

static int	ft_create_mutex_fork(t_vars *vars)
{
	int	i;

	vars->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* vars->number_p);
	i = -1;
	if (vars->forks != NULL)
	{
		while (++i < vars->number_p)
		{
			if (pthread_mutex_init(&vars->forks[i], NULL) != 0)
			{
				free(vars->forks);
				return (-1);
			}
		}
	}
	else
		return (-1);
	return (0);
}

int	ft_create_mutex(t_vars *vars)
{
	if (ft_create_mutex_fork(vars))
		return (-1);
	if (ft_create_mutex_number(vars))
		return (-1);
	if (ft_create_mutex_global(vars))
		return (-1);
	return (0);
}
