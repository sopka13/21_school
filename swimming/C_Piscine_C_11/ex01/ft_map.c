/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:19:41 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/04 14:45:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *c;

	i = 0;
	c = malloc(sizeof(*tab));
	if (c == NULL)
		return (0);
	else
	{
		while (i <= length)
		{
			c[i] = tab[length - i];
			f(c[i]);
			i++;
		}
		return (c);
	}
}
