/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:22:54 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/30 19:49:11 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	ft_write(char *c);

int		main(int argc, char **argv)
{
	char *n;

	(void)argc;
	(void)argv;
	n = argv[0];
	while (*n)
	{
		ft_write(n);
		n++;
	}
	return (0);
}

char	ft_write(char *c)
{
	write(1, c, 1);
	return (0);
}
