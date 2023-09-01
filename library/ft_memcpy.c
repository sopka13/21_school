/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:45:13 by eyohn             #+#    #+#             */
/*   Updated: 2020/11/22 17:12:36 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;

	if (!dest && !src)
		return (NULL);
	if (n == 0 || dest == src)
		return (dest);
	p = (unsigned char*)dest;
	while (n--)
		*p++ = *(unsigned char*)src++;
	return (dest);
}
