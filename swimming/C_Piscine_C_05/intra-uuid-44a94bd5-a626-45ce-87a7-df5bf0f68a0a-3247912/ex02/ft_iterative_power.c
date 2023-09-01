/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:21:57 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/28 18:36:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_out(long int k);

int	ft_iterative_power(int nb, int power)
{
	int			i;
	long int	k;

	k = nb;
	while (power == 0 && nb == 0)
	{
		return (1);
	}
	while (power == 1)
	{
		return (nb);
	}
	while (power > 1)
	{
		i = power - 1;
		while (i != 0)
		{
			k = nb * k;
			i--;
		}
		ft_out(k);
	}
	return (0);
}

int	ft_out(long int k)
{
	if (k <= 2147483647 && k >= -2147483648)
	{
		return (k);
	}
	else
	{
		return (0);
	}
}
