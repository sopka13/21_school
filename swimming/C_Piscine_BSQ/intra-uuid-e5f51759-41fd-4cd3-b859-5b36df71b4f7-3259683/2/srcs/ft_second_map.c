/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:35:45 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 23:12:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_second_map(void)
{
	int i;
	int j;

	i = 0;
	if (!(g_map_num = (int**)malloc(g_line * sizeof(int*))))
		return (1);
	while (i < g_line)
	{
		if(!(g_map_num[i] = (int*)malloc(g_width * sizeof(int))))
			return (1);
		j = 0;
		while (j < g_width)
		{
			if (g_map[i][j] == g_obstacle)
				g_map_num[i][j] = 0;
            else
            {
                if ((i == 0 || j == 0) && (g_map[i][j] == g_empty))
                    g_map_num[i][j] = 1;
                else if (g_map[i][j] == g_empty)
                {
                    if (g_map_num[i - 1][j] == 0)
                        g_map_num[i][j] = 1;
                    if (g_map_num[i - 1][j - 1] == 0)
                        g_map_num[i][j] = 1;
                    if (g_map_num[i][j - 1] == 0)
                        g_map_num[i][j] = 1;
                    else
                    {
                        g_map_num[i][j] = ft_min(g_map_num[i - 1][j], g_map_num[i - 1][j - 1], g_map_num[i][j - 1]) + 1;
                        if (g_min_square < (ft_min(g_map_num[i - 1][j], g_map_num[i - 1][j - 1], g_map_num[i][j - 1]) + 1))
                            g_min_square = (ft_min(g_map_num[i - 1][j], g_map_num[i - 1][j - 1], g_map_num[i][j - 1]) + 1);
                    }
                }
			}
			j++;
		}
		i++;
	}
	return (0);
}
