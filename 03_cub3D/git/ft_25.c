/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_25.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:34:54 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:34:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (len--)
	{
		if (s[start + i] != '\0')
		{
			p[i] = s[start + i];
			i++;
		}
		else
			break ;
	}
	p[i] = '\0';
	free(s);
	s = NULL;
	return (p);
}
