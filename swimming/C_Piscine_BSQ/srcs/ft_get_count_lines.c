/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_count_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:07:18 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 21:07:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int        ft_get_count_lines(char *str_map)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (str_map[i] != '\0')
    {
        if (str_map[i] == '\n')
            num++;
        i++;
    }
    num--;
    return (num);
    printf("ft_get_count_lines ok \n");
}
