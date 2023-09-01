/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:26:04 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:26:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_free_gnl(char *a)
{
	free(a);
	a = NULL;
	return (-1);
}

void		*ft_calloc(size_t n, size_t size)
{
	void	*p;

	p = malloc(n * size);
	if (!p)
		return (NULL);
	ft_bzero(p, n * size);
	return (p);
}

void		*ft_memset(void *s, int c, size_t n)
{
	while (n-- > 0)
		*((unsigned char *)s + n) = (unsigned char)c;
	return (s);
}

void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0x00, n);
}
