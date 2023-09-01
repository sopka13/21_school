/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:20:31 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/29 16:32:57 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_prime(int nb)
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
			return (0);
		}
		i++;
	}
	return (1);
}