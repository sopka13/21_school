/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:13:46 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 21:14:14 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int        ft_get_width(char *str_map)
{
    int i;
    int width;

    i = 0;
    width = 0;
    while (str_map[i] != '\n')
        i++;
    i++;
    while (str_map[i] != '\n')
    {
        i++;
        width++;
    }
    printf("ft_get_width ok \n");
    return (width);
}
