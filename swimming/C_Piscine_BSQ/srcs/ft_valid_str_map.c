/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_str_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:05:17 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 21:05:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void        ft_valid_str_map(char *str_map)
{
    ft_atoi(str_map);
    if (num == 0) // проверка первой строки 1- не валидная
        error = 1;
    else if (num != ft_get_count_lines(str_map))
        error = 1;
    ft_check_letter2(str_map);
    ft_valid_width(str_map);
    printf("ft_valid_str_map ok \n");
}
