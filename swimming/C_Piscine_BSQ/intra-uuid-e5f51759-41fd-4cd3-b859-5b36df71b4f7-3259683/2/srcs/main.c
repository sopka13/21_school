/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:06:43 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 21:22:32 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	**g_map; // массив в который идет запись со стандартного ввода
int		**g_map_num;	// массив в которым ведем подсчет
char    *g_buf;
int		g_line = 0;	// количество строк в исходной карте
char	g_empty = '0';	// символ пустой
char	g_obstacle = '1';	// символ препятствие
char	g_full = '2';	// символ полный
int		g_error = 0;	// значение ошибки
int		g_min_square = 1;	// максимальный размер квадрата
int		g_width = 0;	// длина строк массива

int	main(int argc, char **argv)
{
	int	i = 0;
//	int j = 0;
	if (argc == 1)
	{
		if (ft_input(0) == 1 || ft_check_letter() == 1)
        {
            ft_put_error();
            return (0);
        }
		ft_second_map();	// функция обработки карты на поиск места под квадрат
		ft_finish_map();
		if (g_error == 1)
			ft_put_error();			// если нашли ошибки то выводим					
		else			
			while (i < g_line)
			{
				printf("%s", g_map[i]);
				i++;
			}									// функция вывода на экран карты
		ft_free();
	}
	else
	{
		i = 1;
		while (i < argc)
		{
            if ((ft_size_buf(argv[i]) == 1) || (ft_open_map(argv[i]) == 1))
                ft_put_error();
			else
            {
                ft_output_map();
                
            }
            ft_free();
			i++;
		}
	}
    return (0);
}
