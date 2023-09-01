/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:14:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:31:16 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function return number of philosopher
*/

#include "philo_bonus.h"

int	ft_number_philo(t_vars *vars)
{
	int	number;

	number = vars->number_get++;
	return (number);
}
