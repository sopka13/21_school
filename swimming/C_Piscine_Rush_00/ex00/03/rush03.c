/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:57:00 by mtifany           #+#    #+#             */
/*   Updated: 2020/07/26 13:59:52 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);

void	first(int x)
{
	int a;

	a = 0;
	while (a != x)
	{
		if (a == 0)
		{
			ft_putchar('A');
			a++;
		}
		else
		{
			if (a == x - 1)
			{
				ft_putchar('C');
				a++;
			}
			else
			{
				ft_putchar('B');
				a++;
			}
		}
	}
	ft_putchar('\n');
}

void	middle(int x)
{
	int a;

	a = 0;
	while (a != x)
	{
		if ((a == 0) || (a == x - 1))
		{
			ft_putchar('B');
			a++;
		}
		else
		{
			ft_putchar(' ');
			a++;
		}
	}
	ft_putchar('\n');
}

void	rush03(int x, int y)
{
	int a;

	a = 0;
	if ((x <= 0) || (y <= 0))
		ft_putchar(1);
	else
	{
		while (a != y)
		{
			if ((a == 0) || (a == y - 1))
			{
				first(x);
				a++;
			}
			else
			{
				middle(x);
				a++;
			}
		}
	}
}
