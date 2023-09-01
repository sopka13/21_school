 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:18:32 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 19:54:53 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void ft_open_map(char *name)
{
    int     fd;
    char    buf[30000];
    int     rd;

    fd = open(name, O_RDONLY);                     // открывает карту
    if (fd >= 0)                                 // если открытие успешно
    {
        while ((rd = read(fd, buf, 30000)))        // читает в буфер карту из файла размером 30000
        {
            if (rd == -1)                        // если прочитать не удалось
            {
                error = 1;                 // печать ошибки
                break ;
            }
            else
            {
                buf[rd] = '\0';
                ft_valid_str_map(buf);

                if (error == 1) // проверка на валидность карты
                    ft_put_error();                // вывод ошибки
                else
                    ft_solution_output(buf); // выводит на экран результаты
            }
        }
    }
}
