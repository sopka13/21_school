/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 14:27:39 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/28 14:55:05 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_iterative_factorial(int nb);

int main(void)
{
	int nb;
	int nb1;
	int nb2;
	int nb3;
	int nb4;
	int nb5;

	nb = 0;
	nb1 = 1;
	nb2 = 2;
	nb3 = 3;
	nb4 = -11;
	nb5 = 12;
	printf("%d\n", ft_iterative_factorial(nb));
	printf("%d\n", ft_iterative_factorial(nb1));
	printf("%d\n", ft_iterative_factorial(nb2));
	printf("%d\n", ft_iterative_factorial(nb3));
	printf("%d\n", ft_iterative_factorial(nb4));
	printf("%d\n", ft_iterative_factorial(nb5));
	return 0;
}
