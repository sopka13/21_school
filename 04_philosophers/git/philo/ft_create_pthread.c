/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pthread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:41:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:16:25 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function create pthreads
*/

#include "philo.h"

static int	ft_allocate(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->number_p)
	{
		vars->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!(vars->philos[i]))
			return (-1);
	}
	return (0);
}

int	ft_create_pthread(t_vars *vars)
{
	int	i;
	int	ret;

	vars->philos = (t_philo **)malloc(sizeof(t_philo *)
			* (vars->number_p + 1));
	if (!(vars->philos))
		return (-1);
	vars->philos[vars->number_p] = NULL;
	if (ft_allocate(vars))
		return (-1);
	i = -1;
	while (++i < vars->number_p)
	{
		ret = pthread_create(&vars->philos[i]->pthread, NULL, ft_philo, vars);
		if (ret != 0)
			return (-1);
	}
	vars->retval = (int *)malloc(sizeof(int) * (vars->number_p + 1));
	if (!(vars->retval))
		return (-1);
	vars->retval[vars->number_p] = 0;
	return (0);
}
