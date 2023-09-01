/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:37:28 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/29 19:27:40 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long int	ft_recursive_power_long(long int nb, int power);

int			ft_recursive_power(int nb, int power)
{
	long int	m;

	if (power == 0 && nb == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power < 0 && nb == 1)
		return (1);
	if (power < 0 && nb == -1)
	{
		if (power % 2 != 0)
			return (-1);
		else
			return (1);
	}
	if (power > 1)
	{
		m = ft_recursive_power_long(nb, power);
		if (m <= 2147483647 && m >= -2147483648)
			return (m);
		else
			return (0);
	}
	return (0);
}

long int	ft_recursive_power_long(long int nb, int power)
{
	return (ft_recursive_power(nb, power - 1) * nb);
}
