/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:22:25 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/26 20:28:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int f;
	char l[100];

	f = 0;
	printf("%d\n", ft(str, to_find));
	if (to_find[ft(str, to_find)] == '\0')
	{
		while (str[ft(str, to_find)] != '\0')
		{
			printf("%s\n", "Ok");
			l[f] = str[ft(str, to_find)];
			ft(str, to_find)++;
			f++;
		}
		return (l);
	}
	else
	{
		return (0);
	}
}

int		ft(char *str, char *to_find)
{
	int	i;
	int	k;
	int t;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[k])
		{
			printf("%s\n", "Ok1");
			while (str[i] == to_find[k])
			{
				if (to_find[k] != '\0')
				{
					k++;
					i++;
				}
				else	
				{
					if (to_find[k] == '\0')
					{
						printf("%d\n", i);
						printf("%d\n", k);
						t = i - k;
						return (t);
					}
				}
			}
		}
		if (str[i] != '\0')
		{
			return (0);
		}
		i++;
	}
	printf("%d\n", i);
}
