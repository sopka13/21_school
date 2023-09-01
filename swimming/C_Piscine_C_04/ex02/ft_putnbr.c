/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 10:35:41 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/28 08:45:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_i(int nb);
void	ft_write(char *c);
void	ft_bnul(int i, int h, char *c, int nb);
void	ft_mnul(int i, int h, char *c, int nb);

void	ft_putnbr(int nb)
{
	int		i;
	int		h;
	char	c[30];

	h = ft_i(nb);
	i = ft_i(nb);
	if (nb > 0)
	{
		ft_bnul(i, h, c, nb);
	}
	else if (nb < 0)
	{
		ft_mnul(i, h, c, nb);
	}
	else
	{
		ft_write("0");
	}
}

int		ft_i(int nb)
{
	int i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_write(char *c)
{
	int		i;
	char	x;

	i = 0;
	while (c[i] != '\0')
	{
		x = c[i];
		write(1, &x, 1);
		i++;
	}
}

void	ft_bnul(int i, int h, char *c, int nb)
{
	while (i != 0)
	{
		c[i - 1] = ((nb % 10) + '0');
		nb = nb / 10;
		i--;
	}
	c[h + 1] = '\0';
	ft_write(c);
}

void	ft_mnul(int i, int h, char *c, int nb)
{
	while (i != 0)
	{
		c[i] = ((nb % 10) * (-1) + '0');
		nb = nb / 10;
		i--;
	}
	c[h + 1] = '\0';
	c[0] = '-';
	ft_write(c);
}
