/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:22:03 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/13 10:11:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <libgen.h>
# include <fcntl.h>

extern char	**in_mas;
extern char	s1;
extern char	s2;
extern char	s3;
extern int	**in_mas2;
extern int	num;
extern int	error; // 1 - ошибка в карте
extern int	min;
extern int	str;

void 	ft_input(int a);		// читает со стандартного ввода и заполняет массив
void	ft_atoi(char *a, int b);// получает 1 строку со стандартного ввода и присваивает num, s1, s2, s3;
void	ft_free(void);		// очищает память после выделени под массив
char	*ft_write_in(void);	// читает со стандартного ввода и пишет в массив in_mas
void	ft_put_error(void);	// печать ошибки
void	ft_check_letter(void);	// проверка карты на валидность
void	ft_second_map(void);	// построение промежуточной карты
int		ft_min(int a, int b, int c);	// поиск минимального значения из трехa
void	ft_finish_map(void);	// построение карты на вывод
void	ft_open_map(char *name);		// открывает файл карты
void	ft_valid_str_map(char *str_map); // проверяет на валидность карту файла
int		ft_get_count_lines(char *str_map); // проверяет количество строк в карте
void	ft_check_letter2(char *str_map); // проверка символов в карте
void	ft_valid_width(char *str_map);	// проверка на валидность строк
int		ft_get_width(char *str_map); // получение количества символов в строке
void	ft_solution_output(char *str_map);	// выводит на экран результаты
void	ft_map_arr(char *str_map); // создает многомерный массив
void	ft_strcpy_map(char *str, char *str_map, int line, int width); //построчно  записывает массив

#endif
