/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:03:40 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/11 20:37:39 by eyohn            ###   ########.fr       */
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
