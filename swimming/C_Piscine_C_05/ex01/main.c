/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:36:15 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/28 16:49:11 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_recursive_factorial(int nb);

int main(void)
{
	int nb = 0;
	int nb1 = 1;
	int nb2 = 2;
	int nb3 = 3;
	int nb4 = 12;
	int nb5 = 13;
	printf("%d\n", ft_recursive_factorial(nb));
	printf("%d\n", ft_recursive_factorial(nb1));
	printf("%d\n", ft_recursive_factorial(nb2));
	printf("%d\n", ft_recursive_factorial(nb3));
	printf("%d\n", ft_recursive_factorial(nb4));
	printf("%d\n", ft_recursive_factorial(nb5));
}
