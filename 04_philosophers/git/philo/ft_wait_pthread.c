/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_pthread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:55:39 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 09:52:30 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function wait return status from pthread
*/

#include "philo.h"

int	ft_wait_pthread(t_vars *vars)
{
	int	ret;
	int	i;

	i = -1;
	while (vars->philos[++i] != NULL)
	{
		ret = pthread_join(vars->philos[i]->pthread, (void **)&vars->retval[i]);
		if (ret != 0)
			return (-1);
	}
	return (0);
}
