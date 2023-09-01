/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:51:53 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 23:49:18 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int ft_check_letter(void)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (i < g_line)
	{
		k = 0;
		while (g_map[i][k])
		{
			if (g_map[i][k] != g_empty && g_map[i][k] != g_obstacle && g_map[i][k] != '\n')
			{
                return (1);
			}
			k++;
		}
        if (k == 1)
            return (1);
		i++;
	}
//	printf("Check letter ok \n");
    return (0);
}
