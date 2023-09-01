/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:11:50 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 18:40:16 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_valid_width(char *str_map)
{
	int i;
	int j;

	i = 0;
	ft_get_width(str_map);
	while (str_map[i] != '\n')
		i++;
	i++;
	while (str_map[i] != '\0')
	{
		j = 0;
		while (str_map[i] != '\n' && j <= g_width)
		{
			i++;
			j++;
		}
		if (str_map[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
