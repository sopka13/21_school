/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:38:53 by rtrin             #+#    #+#             */
/*   Updated: 2020/08/09 22:39:36 by rtrin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_teens_tens(unsigned long h, unsigned long t, unsigned long u)
{
	if (h > 0)
	{
		ft_putstr(g_units[h]);
		ft_putstr(" ");
		ft_putstr(g_thou[0]);
		if (t > 0 || u > 0)
			ft_putstr(" and ");
	}
	if (t > 0)
	{
		if (t == 1 && u > 0)
			ft_putstr(g_teens[u - 1]);
		else
		{
			if (t > 0)
				ft_putstr(g_tens[t - 1]);
			if (u > 0)
				ft_putstr("-");
		}
	}
	if (t != 1 && u > 0)
		ft_putstr(g_units[u]);
}

void	ft_print_thous(unsigned long p)
{
	if (p > 0)
	{
		ft_putstr(" ");
		ft_putstr(g_thou[p]);
		ft_putstr(" ");
	}
}

void	ft_print_seps(unsigned long v, unsigned long h, int p)
{
	if ((v > 1000) && (h == 0) && (p == 0))
		ft_putstr(" AND ");
	else
	{
		if (v > 1000)
			ft_putstr(", ");
		else
			ft_putstr("");
	}
}

void	ft_wordify(unsigned long v, int p)
{
	int b;
	int h;
	int t;
	int u;

	if (v == 0 && p == 0)
		ft_putstr(g_units[0]);
	else if (v > 0)
	{
		b = (int)(v % 1000);
		if (b > 0)
		{
			h = (b / 100);
			t = (b - h * 100) / 10;
			u = (b - h * 100 - t * 10);
			ft_print_seps(v, h, p);
			ft_print_teens_tens(h, t, u);
			ft_print_thous(p);
		}
	}
}
