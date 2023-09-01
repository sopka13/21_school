/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 09:01:20 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/03 12:48:04 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_putchar(char *c);

int	main(int argv, char **argc)
{
	int		fp;
	char	base[5000];
	int		k;

	fp = open(argc[1], O_RDONLY);
	if (argv > 2)
	{
		ft_putchar("Too many arguments. \n");
		return (0);
	}
	if (argv < 2)
	{
		ft_putchar("File name missing. \n");
		return (0);
	}
	if (fp == -1)
	{
		ft_putchar("Cannot read file. \n");
		return (0);
	}
	k = read(fp, base, 5000);
	base[k] = '\0';
	ft_putchar(base);
	close(fp);
	return (0);
}

int	ft_putchar(char *c)
{
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
	return (0);
}
