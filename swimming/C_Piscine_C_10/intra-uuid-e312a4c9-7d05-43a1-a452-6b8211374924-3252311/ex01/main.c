/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:52:07 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/04 10:40:01 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	ft_fp(int i, char **argc);
int ft_print(int i, char **argc);

int	main(int argv, char **argc)
{
	int		i;

	i = 1;
	if (argv >= 2)
	{
		if (ft_strcmp(argc[1], "-") == 0)
		{
			input();
		}
		else
		{
			while (i < argv)
			{
				ft_fp(i, argc);
				i++;
			}
		}
		return (0);
	}
	if (argv == 1)
	{
		input();
	}
	return (0);
}

int	ft_fp(int i, char **argc)
{
	int		k;
	int		fp;
	char	base[SIZE_BASE];

	fp = open(argc[i], O_RDONLY);
	if (fp == -1)
	{
		ft_print(i, argc);
	}
	else
	{
		k = read(fp, base, SIZE_BASE);
		if (k == -1)
		{
			ft_print(i, argc);
		}
		base[k] = '\0';
		ft_putchar(base);
		close(fp);
	}
	return (0);
}

int	ft_print(int i, char **argc)
{
	ft_putchar(basename(argc[0]));
	ft_putchar(": ");
	ft_putchar(argc[i]);
	ft_putchar(": ");
	ft_putchar(strerror(errno));
	ft_putchar("\n");
	return (0);
}
