/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:09:10 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/30 20:09:32 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_write(char *c);

int		main(int argc, char **argv)
{
	char	*n;
	int		i;

	i = 1;
	(void)argc;
	(void)argv;
	while (i < argc)
	{
		n = argv[i];
		while (*n)
		{
			ft_write(n);
			n++;
		}
		ft_write("\n");
		i++;
	}
	return (0);
}

char	ft_write(char *c)
{
	write(1, c, 1);
	return (0);
}
