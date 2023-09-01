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

int	ft_sqrt(int nb);

int	main(void)
{
	int nb = 0;
	int nb1 = 2;
	int nb2 = 4;
	int nb3 = 5;
	int nb4 = -2147483648;

	printf("%d\n", ft_sqrt(nb));
	printf("%d\n", ft_sqrt(nb1));
	printf("%d\n", ft_sqrt(nb2));
	printf("%d\n", ft_sqrt(nb3));
	printf("%d\n", ft_sqrt(nb4));
	return (0);
}

