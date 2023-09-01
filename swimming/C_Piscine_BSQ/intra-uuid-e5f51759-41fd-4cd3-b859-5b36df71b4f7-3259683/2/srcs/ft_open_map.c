/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:06:07 by gdilly            #+#    #+#             */
/*   Updated: 2020/08/12 23:04:24 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_open_map(char *name)
{
	int		fd;
	int		rd;

	if (!(g_buf = (char*)malloc(sizeof(char) * (g_size_buf + 1))))
		return (1);
	fd = open(name, O_RDONLY);
	if (fd >= 0)
	{
		while ((rd = read(fd, g_buf, g_size_buf)))
		{
			if (rd == -1)
				return (1);
			else
			{
				g_buf[rd] = '\0';
				if (ft_valid_str_map(g_buf) == 1)
					return (1);
				else
					ft_solution_output(g_buf);
			}
		}
	}
	else
		return (1);
	return (0);
}
