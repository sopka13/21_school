/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:50:25 by eyohn             #+#    #+#             */
/*   Updated: 2020/11/22 17:12:00 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p;
	char	*k;

	if (!dest && !src)
		return (NULL);
	p = (char*)src;
	k = (char*)dest;
	if (p < k)
	{
		p = p + n - 1;
		k = k + n - 1;
		while (n--)
			*k-- = *p--;
	}
	else
		while (n--)
			*k++ = *p++;
	return (dest);
}
