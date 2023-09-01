/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:17:20 by eyohn             #+#    #+#             */
/*   Updated: 2020/11/15 18:17:45 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		len;
	int		i;
	int		k;

	if (!src)
		return (0);
	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	k = size - 1;
	while (k > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		k--;
	}
	dst[i] = '\0';
	return (len);
}
