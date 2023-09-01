/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_programs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:20:21 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/30 11:03:59 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	ft_write(char *c);

int		main(int argc, char **argv)
{
//	char	*n;
	int		l;

	l = 1;
	(void)argc;
	(void)argv;
	printf("%s\n", argv[1]);
//	while ((argc - l) >= 0)
//	{
//		n = argv[argc - l];
//		while (*n)
//		{
//			ft_write(n);
//			n++;
//		}
//		ft_write("\n");
//		l++;
//	}
	return (0);
}

char	ft_write(char *c)
{
	write(1, c, 1);
	return (0);
}
