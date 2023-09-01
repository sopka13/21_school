/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:36:03 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:36:04 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(const char *set, char s)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(set))
		if (s == set[i])
			return (1);
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
