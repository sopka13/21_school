/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 09:25:25 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/04 11:02:25 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_foreach(int *tab, int leght, void(*f)(int));

int main(void)
{
	int tab[5000];
	int i;

	i = 0;
	while (i < 5000)
	{
		tab[i] = i;
		i++;
	}
	ft_foreach(tab, 1337, &ft_putnbr);
	return (0);
}
