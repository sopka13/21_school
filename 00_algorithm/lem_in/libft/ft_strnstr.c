/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:20:57 by eyohn             #+#    #+#             */
/*   Updated: 2020/11/16 19:07:50 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	k;

	i = 0;
	if (!little[i])
		return ((char*)big);
	while (big[i])
	{
		k = 0;
		while (big[i + k] == little[k] && little[k] && i + k < len)
			k++;
		if (!little[k])
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}
