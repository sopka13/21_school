/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 09:17:54 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/01 09:18:31 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_set(int min, int max);
int *ft_null(int *c);
int *ft_write(int *c, int k, int min);

int	ft_ultimate_range(int **range, int min, int max)
{
	int k;
	int *c;

	range = &c;
	if (min == max)
		ft_null(c);
	if (min > max)
		ft_null(c);
	if (min < max)
	{
		k = ft_set(min, max);
		c = malloc(sizeof(k));
		if (c != NULL)
		{
			c = ft_write(c, k, max);
			return (sizeof(c));
		}
		else
			return (-1);
	}
	return (0);
}

int	ft_set(int min, int max)
{
	int m;

	m = (min - max) * (-1);
	return (m);
}

int	*ft_null(int *c)
{
	c = NULL;
	return (0);
}

int	*ft_write(int *c, int k, int min)
{
	int i;

	i = 0;
	while (i < k)
	{
		c[i] = min + i;
		i++;
	}
	return (0);
}
