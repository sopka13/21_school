/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:07:31 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:21:48 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_exit(t_vars *vars, int status)
{
	int	i;

	i = -1;
	while (++i < vars->number_p)
		free(vars->philos[i]);
	free(vars->philos);
	free(vars->retval);
	exit(status);
	return (0);
}
