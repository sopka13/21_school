/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 09:01:32 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/11 20:34:11 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!dest)
		return (NULL);
	if (!n)
		return (dest);
	while (i < n)
	{
		if (i < ft_strlen(src))
		{
			dest[i] = src[i];
			i++;
			continue;
		}
		dest[i++] = 0;
	}
	dest[i] = '\0';
	return (dest);
}
