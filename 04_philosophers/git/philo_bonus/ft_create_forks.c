/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:41:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:29:52 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function create forks
*/

#include "philo_bonus.h"

int	ft_create_forks(t_vars *vars)
{
	int	i;
	int	ret;

	vars->philos = (t_philo **)malloc(sizeof(t_philo *) * (vars->number_p + 1));
	vars->retval = (int *)malloc(sizeof(int) * vars->number_p);
	if (!(vars->philos) || !(vars->retval))
		return (-1);
	vars->philos[vars->number_p] = NULL;
	i = -1;
	while (++i < vars->number_p)
	{
		vars->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (vars->philos[i] != NULL)
		{
			vars->philos[i]->number = i;
			vars->philos[i]->philos = fork();
			if (vars->philos[i]->philos == 0 && ft_philo(vars, i))
				return (1);
			else if (vars->philos[i]->philos > 0)
				continue ;
			else if (vars->philos[i]->philos < 0)
				return (-1);
		}
	}
	return (0);
}
