/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:34:35 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:34:40 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == c && i != 0 && s[i - 1] != c && s[i] != '\0')
				|| (s[i] != c && s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

static char	**ft_free(char **p)
{
	int		i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
	return (NULL);
}

char		**ft_split(const char *str, char c)
{
	char	**str_1;
	t_split	s;

	ft_bzero(&s, sizeof(s));
	if (!str)
		return (NULL);
	if (!(str_1 = ft_calloc((ft_count(str, c) + 1), sizeof(char*))))
		return (NULL);
	str_1[ft_count(str, c)] = NULL;
	while (s.m < ft_count(str, c) && str[s.i] != '\0')
	{
		s.n = 0;
		s.l = 0;
		while (str[s.i] == c && str[s.i] != '\0')
			s.i++;
		while (str[s.i + s.l] != c && str[s.i + s.l] != '\0')
			s.l++;
		if (!(str_1[s.m] = ft_calloc(s.l + 1, sizeof(char))))
			return (ft_free(str_1));
		while (s.n < s.l)
			str_1[s.m][s.n++] = str[s.i++];
		str_1[s.m++][s.n] = '\0';
	}
	return (str_1);
}
