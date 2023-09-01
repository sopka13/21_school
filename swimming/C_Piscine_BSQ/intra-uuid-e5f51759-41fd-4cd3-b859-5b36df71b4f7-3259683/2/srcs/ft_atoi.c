/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:56:41 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 18:31:45 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_atoi(char *line, int a)
{
	int	b;

	g_line = 0;
	b = 0;
	if (g_full == '2')
		g_full = line[a];
	else
		return (1);
	if (g_obstacle == '1' && (line[a] != line[a - 1]))
		g_obstacle = line[a - 1];
	else
		return (1);
	if ((g_empty == '0') && (line[a] != line[a - 1]) &&
	(line[a] != line[a - 2]))
		g_empty = line[a - 2];
	else
		return (1);
	while (line[b] >= '0' && line[b] <= '9' && b <= (a - 3))
	{
		g_line = g_line * 10 + line[b] - '0';
		b++;
	}
	if ((b + 2) != a)
		return (1);
	return (0);
}
