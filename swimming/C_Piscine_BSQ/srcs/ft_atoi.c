/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:56:41 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 19:54:26 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_atoi(char *a)
{
	int	b;
    int d;

	b = 0;
    d = -1;
	while (a[b] > '0' && a[b] <= '9')
	{
		num = num * 10 + a[b] - '0';
		b++;
	}
	while (a[b] != '\n')
	{
		if (s1 == '0')
			s1 = a[b];
		else if (s2 == '1' && (a[b] != a[b - 1]))
			s2 = a[b];
		else if (s3 == '2' && (a[b] != a[b - 1]) && (a[b] != a[b - 2]))
			s3 = a[b];
		else if (d++ == 3)
		{
			error = 1;
			break ;
		}
		b++;
	}
}
