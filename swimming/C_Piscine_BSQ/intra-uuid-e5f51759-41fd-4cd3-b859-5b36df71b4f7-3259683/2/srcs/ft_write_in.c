/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:30:28 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 23:11:10 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char *ft_write_in(void)
{
	int str_2;
	int	a;

	str_2 = 0;
	a = 0;
	if (!(g_map = (char**)malloc(g_line * sizeof(char*))))
		return (NULL);
	while (a < g_line)
	{
		if(!(g_map[a] = (char*)malloc(30000 * sizeof(char))))
			return (NULL);
		g_width = read(0, g_map[a], 30000);
		if (g_width == 0)
		{
			g_error = 1;
			break ;
		}
		if ((str_2 != 0) && (g_width != str_2))
		{
			g_error = 1;
			break ;
		}
		str_2 = g_width;
		a++;
	}
	g_width = g_width - 1;
	return (g_map[0]);
}
