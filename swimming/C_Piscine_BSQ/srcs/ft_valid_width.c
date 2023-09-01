/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:11:50 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 21:12:28 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void        ft_valid_width(char *str_map)
{
    int i;
    int width;
    int j;

    i = 0;
    width = ft_get_width(str_map);
    while (str_map[i] != '\n')
        i++;
    i++;
    while (str_map[i] != '\0')
    {
        j = 0;
        while (str_map[i] != '\n' && j <= width)
        {
            i++;
            j++;
        }
        if (str_map[i] != '\n')
        {
            error = 1;
            break ;
        }
        i++;
    }
    printf("ft_valid_width ok \n");
}
