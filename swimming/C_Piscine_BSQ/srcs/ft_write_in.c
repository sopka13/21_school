/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:30:28 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 18:13:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char *ft_write_in(void)
{
	int str_2;
	int	a;

	str_2 = 0;
	a = 0;
	if (!(in_mas = (char**)malloc(num * sizeof(char*))))
		printf("Память не выделена");
	while (a < num)
	{
		if(!(in_mas[a] = (char*)malloc(100 * sizeof(char))))
			printf("Память не выделена");
		str = read(0, in_mas[a], 100);
		if (str == 0)
		{
			error = 1;
			break ;
		}
		if ((str_2 != 0) && (str != str_2))
		{
			error = 1;
			break ;
		}
		str_2 = str;
		a++;
	}
	str = str - 1;
	printf("Write ok \n");
	return (in_mas[0]);
}
