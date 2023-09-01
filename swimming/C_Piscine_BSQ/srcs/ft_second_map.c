/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:35:45 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 18:01:38 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_second_map(void)
{
	int i;
	int j;

	i = 0;
	printf("Second start \n");
	if (!(in_mas2 = (int**)malloc(num * sizeof(int*))))
		printf("Память не выделена");
	while (i < num)
	{
		if(!(in_mas2[i] = (int*)malloc(100 * sizeof(int))))
			printf("Память не выделена");
		j = 0;
		while (j < str)
		{
			if (in_mas[i][j] == s2)
				in_mas2[i][j] = 0;
			else if (i == 0 || j == 0)
				in_mas2[i][j] = 1;
			else if (in_mas[i][j] == s1)
			{
				if (in_mas2[i - 1][j] == 0)
					in_mas2[i][j] = 1;
				if (in_mas2[i - 1][j - 1] == 0)
					in_mas2[i][j] = 1;
				if (in_mas2[i][j - 1] == 0)
					in_mas2[i][j] = 1;
				else
				{
					in_mas2[i][j] = ft_min(in_mas2[i - 1][j], in_mas2[i - 1][j - 1], in_mas2[i][j - 1]) + 1;
					if (min < (ft_min(in_mas2[i - 1][j], in_mas2[i - 1][j - 1], in_mas2[i][j - 1]) + 1))
						min = (ft_min(in_mas2[i - 1][j], in_mas2[i - 1][j - 1], in_mas2[i][j - 1]) + 1);
				}
			}
			j++;
		}
		i++;
	}
	printf("Recursive map ok \n");
}
