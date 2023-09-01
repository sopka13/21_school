/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:15:24 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 20:28:25 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_free(void)
{
	int	i;

	i = 0;
	while (i < g_line)
	{
		free(g_map[i]);
		free(g_map_num[i]);
		i++;
	}
    free(g_buf);
	g_line = 0;
	g_empty = '0';
	g_obstacle = '1';
	g_full = '2';
	g_error = 0;
	g_min_square = 1;
	g_width = 0;
}
