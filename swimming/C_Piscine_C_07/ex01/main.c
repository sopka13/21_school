/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:22:06 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/31 08:19:57 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int min;
	int max;
	int *a;
	int i;

	min = 0;
	max = 123;
	i = 0;
	a = ft_range(min, max);
	printf("%x\n", (unsigned int)a);
	while ((i + min) != max)
	{
		printf("%d\n", a[i]);
		i++;
	}
	return (0);
}
