/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:38:21 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 16:27:35 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		return (ft_strdup(""));
	}
	k = ft_strlen((char *)s1) - 1;
	while (ft_set(set, s1[k]) && k > 0)
		k--;
	return (ft_substr(s1, i, k - i + 1));
}
