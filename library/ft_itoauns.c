/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoauns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:39:07 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/11 20:39:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num2(unsigned int l)
{
	int		a;

	a = 0;
	if (l > 0)
	{
		while (l != 0)
		{
			l = l / 10;
			a++;
		}
		a++;
	}
	else
		a = 2;
	return (a);
}

char		*ft_itoauns(unsigned int n)
{
	char	*p;
	int		num;

	num = ft_num2(n);
	p = malloc(sizeof(char) * num);
	if (!p)
		return (NULL);
	p[--num] = '\0';
	while (num--)
	{
		p[num] = n % 10 + '0';
		n /= 10;
	}
	return (p);
}
