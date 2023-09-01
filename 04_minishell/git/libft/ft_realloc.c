/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:34:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:23:49 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc_source(char *ptr, char *new)
{
	free(ptr);
	return (new);
}

void		*ft_realloc(char *ptr, size_t new_size)
{
	char	*new;
	size_t	lenght;
	size_t	i;

	if (!ptr || new_size == 0)
		return (NULL);
	i = -1;
	if (!(new = (char*)ft_calloc(1, new_size + 1)))
		return (NULL);
	lenght = ft_strlen(ptr);
	if (lenght >= new_size)
		while (++i < new_size && ptr[i])
		{
			if (i < lenght)
				new[i] = ptr[i];
			else
				new[i] = '\0';
		}
	else
	{
		while (++i < new_size && ptr[i])
			new[i] = ptr[i];
		new[i] = '\0';
	}
	return (ft_realloc_source(ptr, new));
}
