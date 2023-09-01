/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:19:38 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 21:20:03 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void    ft_strcpy_map(char *st, char *str_map, int line, int width)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str_map[i] != '\n')
    {
        i++;
    }
    i++;
    i = i + (line * (width + 1));
    while (str_map[i] != '\n')
    {
        st[j] = str_map[i];
        j++;
        i++;
    }
    st[j] = '\n';
    printf("ft_strcpy_map ok \n");
    while (i < num) // распечатать ин мас
    {
        j = 0;
        while (j < str)
        {
            printf("%c", in_mas[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
