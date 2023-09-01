/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:18:29 by rtrin             #+#    #+#             */
/*   Updated: 2020/08/09 22:27:44 by rtrin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_read_dict(void)
{
	int		d_len;
	int		fd;
	char	b;
	char	*dict;

	d_len = 0;
	dict = NULL;
	if ((fd = open(g_dict_name, O_RDONLY)) != -1)
	{
		while (read(fd, &b, 1) > 0)
			d_len++;
		close(fd);
		if (d_len && (dict = malloc(d_len * sizeof(char))))
		{
			if ((fd = open(g_dict_name, O_RDONLY)) != -1)
			{
				if (d_len != read(fd, dict, d_len))
					dict = NULL;
				close(fd);
			}
		}
	}
	return (dict);
}
