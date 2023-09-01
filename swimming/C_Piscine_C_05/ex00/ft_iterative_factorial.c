/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 14:33:16 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/28 16:18:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int i;
	int k;
	int c;

	i = 1;
	k = nb - 1;
	c = nb;
	if (nb > 1 && nb <= 12)
	{
		while (nb > 1 && k != 0)
		{
			nb = nb * k;
			k--;
		}
	}
	else if (nb == 0 || nb == 1)
	{
		return (1);
	}
	else if (nb < 0 || nb > 12)
	{
		return (0);
	}
	return (nb);
}
