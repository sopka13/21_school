/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:17:33 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 19:55:27 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_map_arr(char *str_map)
{
	int i;

	i = 0;
	if (!(g_map = (char**)malloc(sizeof(char*) * (g_line + 1))))
		return (1);
	while (i < g_line)
	{
		if (!(g_map[i] = (char*)malloc(sizeof(char) * (g_width + 1))))
			return (1);
		ft_strcpy_map(g_map[i], str_map, i);
		i++;
	}
	g_map[i] = 0;
	return (0);
}
