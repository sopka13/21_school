/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:34:17 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:34:18 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num(unsigned long long int k)
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

static int	ft_num2(unsigned long long int l)
{
	int		a;

	if (l > 0)
		a = ft_num(l) + 1;
	else
		a = 2;
	return (a);
}

char		*ft_itoa_llu(unsigned long long int n)
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
