/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_letter2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:09:30 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 21:09:33 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void        ft_check_letter2(char *str_map)
{
    int i;

    i = 0;
    while(str_map[i] != '\n')
       i++;
    while (str_map[i] != '\0')
    {
        if (str_map[i] != s1 &&  str_map[i] != s2 && str_map[i] != '\n')
        {
            error = 1;
            break ;
        }
        i++;
    }
    printf("ft_check_letter ok \n");
}
