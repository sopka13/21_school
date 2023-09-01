/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime_next_prime.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:43:48 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/29 16:49:57 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_prime_next_prime(int nb)
{
	int i;
	int k;

	i = 2;
	if (nb < 0)
		return (0);
	while (i < nb)
	{
		k = nb % i;
		if (k == 0)
		{
			nb = nb + 1;
		}
		i++;
	}
	return (nb);
}
