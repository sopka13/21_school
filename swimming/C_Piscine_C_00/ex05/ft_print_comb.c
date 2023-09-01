/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 08:31:01 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/09 12:47:43 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_num(char b, char c, char d)
{
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, &d, 1);
	write(1, ",", 1);
	write(1, " ", 1);
}

void	ft_print_comb(void)
{
	char b;
	char c;
	char d;

	b = '0';
	while (b <= '7')
	{
		c = b + 1;
		while (c <= '8')
		{
			d = c + 1;
			while (d <= '9')
			{
				ft_num(b, c, d);
				d++;
			}
			c++;
		}
		b++;
	}
}
