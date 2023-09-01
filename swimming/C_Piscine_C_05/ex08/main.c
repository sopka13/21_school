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

int	ft_ten_queens_puzzle(int nb);

int	main(void)
{
    int nb = 8;
    int nb1 = 9;
    int nb2 = 10;

	printf("%d\n", ft_ten_queens_puzzle(nb));
	printf("%d\n", ft_ten_queens_puzzle(nb1));
	printf("%d\n", ft_ten_queens_puzzle(nb2));
	return (0);
}

