/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:38:33 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/28 12:59:29 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_z(int z);

int	ft_atoi(char *str)
{
	int i;
	int z;
	int q;

	i = 0;
	z = 0;
	q = 0;
	while ((str[i] == 32) || (str[i] <= 13 && str[i] >= 9))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			z++;
		}
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		q = q * 10 + str[i] - '0';
		i++;
	}
	return (q * ft_z(z));
}

int	ft_z(int z)
{
	int r;

	if (z % 2 == 0)
	{
		r = 1;
	}
	else
	{
		r = -1;
	}
	return (r);
}
