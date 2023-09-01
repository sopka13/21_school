/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:58:15 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/31 08:17:26 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_set(int min, int max);

int	*ft_range(int min, int max)
{
	int i;
	int k;
	int *c;

	i = 0;
	if (min == max)
		return (NULL);
	if (min > max)
		return (NULL);
	if (min < max)
	{
		k = ft_set(min, max);
		c = malloc(sizeof(k));
		while (i < k)
		{
			c[i] = min + i;
			i++;
		}
		return (c);
	}
	return (0);
}

int	ft_set(int min, int max)
{
	int m;

	m = (min - max) * (-1);
	return (m);
}
