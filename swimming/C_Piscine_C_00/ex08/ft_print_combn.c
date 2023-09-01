/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:55:20 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/09 12:29:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_me(int *arr, int col, int n)
{
	int		i;

	while (col)
	{
		while (arr[col] == (9 + col - (n - 1)) && col >= 0)
			col -= 1;
		if (col < 0)
			break ;
		arr[col] += 1;
		i = col;
		while (i++ < n)
			arr[i] = arr[i - 1] + 1;
		col = n - 1;
		ft_putchar(',');
		ft_putchar(' ');
		i = 0;
		while (i < n)
			ft_putchar(arr[i++] + '0');
	}
}

void		ft_print_combn(int n)
{
	int		arr[n];
	int		i;
	int		col;

	col = n - 1;
	if (n > 10)
		return ;
	i = -1;
	while (i++ < n)
		arr[i] = i;
	i = 0;
	while (i < n)
		ft_putchar(arr[i++] + '0');
	ft_me(arr, col, n);
	ft_putchar('\n');
}
