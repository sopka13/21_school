/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:45:15 by eyohn             #+#    #+#             */
/*   Updated: 2020/11/18 20:28:44 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (p);
}
