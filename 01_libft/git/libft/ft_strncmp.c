/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:19:49 by eyohn             #+#    #+#             */
/*   Updated: 2020/11/15 18:20:46 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)s1 > *(unsigned char*)s2)
			return (1);
		else if (*(unsigned char*)s1 < *(unsigned char*)s2)
			return (-1);
		else if (*(unsigned char*)s1 == 0 || *(unsigned char*)s2 == 0)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
