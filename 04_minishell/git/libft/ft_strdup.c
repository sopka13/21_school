/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:35:05 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:35:06 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * i + 1);
	if (!p)
		return (NULL);
	while (i >= 0)
	{
		p[i] = src[i];
		i--;
	}
	p[ft_strlen(src)] = '\0';
	return (p);
}
