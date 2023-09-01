/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_letter2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:09:30 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 18:38:03 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_check_letter2(char *str_map)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str_map[i] != '\n')
		i++;
	while (str_map[i] != '\0')
	{
		if (str_map[i] == g_empty || str_map[i] == g_obstacle)
			k++;
		if (str_map[i] != g_empty && str_map[i]
				!= g_obstacle && str_map[i] != '\n')
			return (1);
		i++;
	}
	if (k == 0)
		return (1);
	return (0);
}
