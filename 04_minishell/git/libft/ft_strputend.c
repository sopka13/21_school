/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strputend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:35:54 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:35:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strputend(char *a, char b)
{
	char	*c;
	int		i;

	i = 0;
	if (!a)
		return (NULL);
	if (!(c = (char*)malloc((int)ft_strlen(a) + 2)))
		return (NULL);
	while (a[i])
	{
		c[i] = a[i];
		i++;
	}
	c[i++] = b;
	c[i] = '\0';
	free(a);
	a = NULL;
	return (c);
}
