/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:10:58 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/30 20:11:18 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_write(char *c);

int		main(int argc, char **argv)
{
	char	*n;
	int		l;

	l = 1;
	(void)argc;
	(void)argv;
	while ((argc - l) > 0)
	{
		n = argv[argc - l];
		while (*n)
		{
			ft_write(n);
			n++;
		}
		ft_write("\n");
		l++;
	}
	return (0);
}

char	ft_write(char *c)
{
	write(1, c, 1);
	return (0);
}
