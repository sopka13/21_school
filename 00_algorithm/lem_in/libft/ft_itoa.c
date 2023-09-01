/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:28:25 by eyohn             #+#    #+#             */
/*   Updated: 2020/11/15 17:35:58 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num(int k)
{
	int		i;

	i = 0;
	while (k != 0)
	{
		k = k / 10;
		i++;
	}
	return (i);
}

static int	ft_num2(int l)
{
	int		a;

	if (l < 0)
		a = ft_num(l) + 2;
	else if (l > 0)
		a = ft_num(l) + 1;
	else
		a = 2;
	return (a);
}

char		*ft_itoa(int n)
{
	char	*p;
	int		m;
	int		num;

	m = 0;
	num = ft_num2(n);
	if (n < 0)
		m++;
	p = malloc(sizeof(char) * num);
	if (!p)
		return (NULL);
	p[--num] = '\0';
	while (num--)
	{
		if (n < 0)
			p[num] = (n % 10) * (-1) + '0';
		else
			p[num] = n % 10 + '0';
		n /= 10;
	}
	if (m)
		p[0] = '-';
	return (p);
}
