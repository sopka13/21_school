/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_buf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:21:47 by gdilly            #+#    #+#             */
/*   Updated: 2020/08/12 17:22:30 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

long int		ft_size_buf(char *file)
{
	int		fd;
	char	buf[1];
	int		tmp;

	g_size_buf = 0;
	if (-1 == (fd = open(file, O_RDONLY)))
	{
		return (1);
	}
	else
	{
		while ((tmp = read(fd, buf, 1)) > 0)
			g_size_buf++;
		if ((tmp = close(fd)) < 0)
			return (1);
	}
	return (g_size_buf);
}
