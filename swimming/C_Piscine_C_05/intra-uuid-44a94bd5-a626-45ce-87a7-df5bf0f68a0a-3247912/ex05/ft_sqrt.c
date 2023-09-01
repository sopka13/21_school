/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:36:04 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/29 16:36:24 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int i;
	int k;

	if (nb == 0)
		return (0);
	else if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	else
	{
		i = 1;
		while (i != nb)
		{
			k = i * i;
			if (k == nb)
			{
				return (i);
			}
			i++;
		}
	}
	return (0);
}
