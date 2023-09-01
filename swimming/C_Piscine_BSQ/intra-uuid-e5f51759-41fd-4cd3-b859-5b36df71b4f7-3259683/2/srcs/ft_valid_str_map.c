/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_str_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:05:17 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 18:33:23 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_valid_str_map(char *str_map)
{
	int i;

	i = 0;
	while (str_map[i] != '\n')
		i++;
	i--;
	if (ft_atoi(str_map, i) == 1)
		return (1);
	else if (g_line != ft_get_count_lines(str_map))
		return (1);
	if (ft_check_letter2(str_map) == 1 || ft_valid_width(str_map) == 1)
		return (1);
	return (0);
}
