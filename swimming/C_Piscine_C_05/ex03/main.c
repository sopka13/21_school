/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:09:40 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/29 07:38:12 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int	main(void)
{
	int nb = 0;
	int power = 0;
	int nb1 = -1;
	int power1 = 9;
	int nb2 = 2;
	int power2 = -2;
	int nb3 = -1;
	int power3 = 0;
	int nb4 = -2;
	int power4 = 2;
	int nb5 = 46341;
	int power5 = 2;

	printf("%d\n", ft_recursive_power(nb, power));
	printf("%d\n", ft_recursive_power(nb1, power1));
	printf("%d\n", ft_recursive_power(nb2, power2));
	printf("%d\n", ft_recursive_power(nb3, power3));
	printf("%d\n", ft_recursive_power(nb4, power4));
	printf("%d\n", ft_recursive_power(nb5, power5));
	return (0);
}

