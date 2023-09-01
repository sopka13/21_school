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

int	ft_fibonacci(int index);

int	main(void)
{
	int index = 0;
	int index1 = 1;
	int index2 = 46;
	int index3 = 12;
	int index4 = -42;

	printf("%d\n", ft_fibonacci(index));
	printf("%d\n", ft_fibonacci(index1));
	printf("%d\n", ft_fibonacci(index2));
	printf("%d\n", ft_fibonacci(index3));
	printf("%d\n", ft_fibonacci(index4));
	return (0);
}

