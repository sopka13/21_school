/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 08:31:01 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/09 12:44:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_num(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	write(1, ",", 1);
	write(1, " ", 1);
}

void	ft_print_comb2(void)
{
	char a;
	char b;
	char c;
	char d;

	a = '/';
	while (a++ < '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = '0';
			while (c <= '9')
			{
				d = b + 1;
				while (d <= '9')
				{
					ft_num(a, b, c, d);
					d++;
				}
				c++;
			}
			b++;
		}
	}
}
