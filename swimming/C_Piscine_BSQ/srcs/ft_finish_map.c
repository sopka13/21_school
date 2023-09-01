/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:11:13 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 18:13:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void ft_finish_map(void)
{
    int i;
    int j;

	i = 0;
    j = 0;
	printf("Ft finish start \n");
	while (i < num) // распечатать ин мас
	{
		j = 0;
		while (j < str)
		{
			printf("%c", in_mas[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	j = 0;
	printf("%d\n", in_mas2[0][0]);
	while (i < num) // распечатать ин мас2
	{
		j = 0;
		while (j < str)
		{
			printf("%d", in_mas2[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("Print ok \n");
	i = 0;
	j = 0;
	while (i < num)
    {
        j = 0;
        while (j < str)
        {
            if (in_mas2[i][j] == min)
            {
                int p = 0;
                int q = 0;
                while (p < min)
                {
                    q = 0;
                    while (q < min)
                    {
                        in_mas[i - p][j - q] = s3;
                        q++;
                    }
                    p++;
                }
                break ;
            }
            j++;
        }
        i++;
    }
	printf("Карта составлена \n");
}
