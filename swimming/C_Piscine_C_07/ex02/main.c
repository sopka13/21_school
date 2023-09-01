/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 08:24:02 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/01 09:19:42 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int min;
	int max;
	int **range;
	int i;
    int a;

	min = -13;
	max = 2000;
	i = 0;
    range = NULL;
	a = ft_ultimate_range(range, min, max);
	printf("%d\n", a);
	return (0);
}
