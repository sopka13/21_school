/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:17:33 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 21:17:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void    ft_map_arr(char *str_map)
{
//    char **map_arr;
//    char *str;
    int width;
    int i;
    
    i = 0;
    width = ft_get_width(str_map);
    if (!(in_mas = (char**)malloc(sizeof(char*) * (num + 1))))
        printf("Память не выделена");
    while (i < num)
    {
//        if(!(str = (char*)malloc(sizeof(char) * (width + 1))))
//            printf("Память не выделена");
        if(!(in_mas[i] = (char*)malloc(sizeof(char) * (width + 1))))
            printf("Память не выделена");
//      ft_strcpy_map(str, str_map, i, width);
        ft_strcpy_map(in_mas[i], str_map, i, width);
//      in_mas[i] = str;
        i++;
    }
    in_mas[i] = 0;
    printf("ft_map_arr ok \n");
}
