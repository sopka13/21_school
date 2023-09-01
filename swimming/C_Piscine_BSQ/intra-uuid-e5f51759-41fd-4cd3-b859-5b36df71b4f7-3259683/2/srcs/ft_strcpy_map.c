/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:19:38 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 18:55:35 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		ft_strcpy_map(char *st, char *str_map, int line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str_map[i] != '\n')
		i++;
	i++;
	i = i + (line * (g_width + 1));
	while (str_map[i] != '\n')
	{
		st[j] = str_map[i];
		j++;
		i++;
	}
	st[j] = '\n';
}
