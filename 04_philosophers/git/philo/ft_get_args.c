/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:41:46 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:04:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function get args and put them into the structure
**	return (0) - success
**	return (-1) - error
*/

#include "philo.h"

static void	ft_start_time(t_vars *vars)
{
	gettimeofday(&vars->time, NULL);
	vars->start_time = vars->time.tv_usec / 1000;
	vars->start_time += vars->time.tv_sec * 1000;
}

int	ft_get_args(int argc, char **argv, t_vars *vars)
{
	if (argc < 5 || argc > 6)
		return (-1);
	vars->number_p = ft_atoi(argv[1]);
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars->number_eat = ft_atoi(argv[5]);
	if (vars->number_p <= 0 || vars->time_to_die <= 0 || vars->time_to_eat <= 0
		|| vars->time_to_sleep <= 0 || (argc == 6 && vars->number_eat <= 0))
		return (-1);
	ft_start_time(vars);
	return (0);
}
