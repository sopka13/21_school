/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:11:13 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 20:47:40 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_finish_map(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_line)
	{
		j = 0;
		while (j < g_width)
		{
			if (g_map_num[i][j] == g_min_square)
			{
				ft_build_max_square(i, j, g_min_square);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
