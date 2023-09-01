/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 09:25:25 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/04 14:25:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_putint(int c);
int		*ft_map(int *tab, int leght, int (*f)(int));

int		main(void)
{
	int tab[1000];
	int i;
	int *c;
    int (*f)(int);

	i = 0;
    f = &ft_putint;
	while (i < 1000)
	{
		tab[i] = i;
		i++;
	}
    c = ft_map(tab, 100, f);
	return (0);
}
