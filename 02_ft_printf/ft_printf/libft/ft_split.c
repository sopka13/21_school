/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:26:16 by eyohn             #+#    #+#             */
/*   Updated: 2020/11/23 14:33:37 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_k(const char *s, char c)
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

static int	ft_l(const char *s, int i, char c, int m)
{
	int		l;

	l = 0;
	if (m == 1)
	{
		while (s[i] != c && s[i++] != '\0')
			l++;
		return (l);
	}
	else
	{
		if (s[i] == c && s[i] != '\0')
		{
			while (s[i] == c)
				i++;
		}
		return (i);
	}
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

char		**ft_split(const char *s, char c)
{
	char	**p;
	int		a[5];

	ft_bzero(a, (sizeof(int) * 5));
	if (!s)
		return (NULL);
	a[1] = ft_k(s, c);
	if (!(p = ft_calloc((a[1] + 1), sizeof(char*))))
		return (NULL);
	p[a[1]] = NULL;
	while (a[3] < a[1] && s[a[0]] != '\0')
	{
		a[4] = 0;
		a[0] = ft_l(s, a[0], c, 0);
		a[2] = ft_l(s, a[0], c, 1);
		if (!(p[a[3]] = ft_calloc(a[2] + 1, sizeof(char))))
			return (ft_free(p));
		while (a[4] < a[2])
			p[a[3]][a[4]++] = s[a[0]++];
		p[a[3]++][a[4]] = '\0';
	}
	return (p);
}
