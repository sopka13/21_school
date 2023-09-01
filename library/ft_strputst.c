/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strputst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:30:04 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/11 20:30:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strputst(char *a, char b)
{
	char	*c;
	int		i;

	i = 0;
	if (!a)
		return (NULL);
	if (!(c = (char*)malloc((int)ft_strlen(a) + 2)))
		return (NULL);
	if (a[0] == '-' && b == '0')
	{
		c[i++] = '-';
		c[i++] = b;
	}
	else
		c[i++] = b;
	while (a[i - 1])
	{
		c[i] = a[i - 1];
		i++;
	}
	c[i] = '\0';
	free(a);
	a = NULL;
	return (c);
}
