/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_24.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:34:47 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:34:48 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_set(const char *set, char s)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char *s1, const char *set)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_set(set, s1[i]))
		i++;
	if (s1[i] == '\0')
	{
		free(s1);
		s1 = NULL;
		return (ft_strdup(""));
	}
	k = ft_strlen((char *)s1) - 1;
	while (ft_set(set, s1[k]) && k > 0)
		k--;
	return (ft_substr(s1, i, k - i + 1));
}
