/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:09:40 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/29 10:57:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	int nb = 0;
	int nb1 = 2;
	int nb2 = 4;
	int nb3 = 5;
	int nb4 = 83;

	printf("%d\n", ft_find_next_prime(nb));
	printf("%d\n", ft_find_next_prime(nb1));
	printf("%d\n", ft_find_next_prime(nb2));
	printf("%d\n", ft_find_next_prime(nb3));
	printf("%d\n", ft_find_next_prime(nb4));
	return (0);
}

