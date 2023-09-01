/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:19:19 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:43:31 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_star(int *num, t_modify *modify, va_list ap)
{
	char	*b;
	int		i;

	i = 0;
	if (modify->starprev > 1 || modify->starpost > 1)
	{
		ft_putchar('%');
		ft_putnbr(modify->num1);
		num[0] += modify->num1 + 1;
		if (modify->starpost > 1)
		{
			ft_putchar('.');
			ft_putnbr(modify->num2);
			num[0] += modify->num2 + 1;
		}
		return (num[1]++);
	}
	b = ft_itoa(va_arg(ap, int));
	while (b[i])
	{
		ft_relative(b[i++], modify, num);
		num[1]--;
	}
	free(b);
	return (0);
}

static void	ft_char(char *str, int *num, t_modify *modify, va_list ap)
{
	if (str[num[1]] == 'd')
		ft_di(num, modify, ap);
	else if (str[num[1]] == 'u')
		ft_u(num, modify, ap);
	else if (str[num[1]] == 's')
		ft_s(num, modify, ap);
	else if (str[num[1]] == 'p')
		ft_p(num, modify, ap);
	else if (str[num[1]] == 'x' || str[num[1]] == 'X')
		ft_x(str, num, modify, ap);
	else if (str[num[1]] == 'i')
		ft_di(num, modify, ap);
	else if (str[num[1]] == 'c')
		ft_c(num, modify, ap);
	return ;
}

static int	ft_spec(char c)
{
	if (c == 'u' || c == 'h' || c == 'd' || c == 'x' || c == 'X'
			|| c == 'o' || c == 'l' || c == 'f' || c == 'e' || c == 's'
			|| c == 'c' || c == 'i' || c == 'p')
		return (1);
	else
		return (0);
}

static int	ft_relative2(char c)
{
	if (c == ' ' || c == '-' || c == '+' || c == '0' || c == '#' ||
			c == '*' || c == '.' || c == '%')
		return (1);
	else
		return (0);
}

void		ft_printf_1(char *str, int *num, t_modify *modify, va_list ap)
{
	while (ft_spec(str[num[1]]) || ft_relative2(str[num[1]]) ||
			ft_isdigit(str[num[1]]))
	{
		if (ft_relative(str[num[1]], modify, num) == 1)
			continue;
		if (ft_isdigit(str[num[1]]) && ft_digit(str[num[1]], modify, num))
			continue;
		if (ft_spec(str[num[1]]))
		{
			ft_char(str, num, modify, ap);
			break ;
		}
		if (str[num[1]] == '*')
		{
			ft_star(num, modify, ap);
			if (modify->starprev > 1 || modify->starpost > 1)
				break ;
		}
		if (str[num[1]] == '%')
		{
			ft_percent(num, modify);
			break ;
		}
		num[1]++;
	}
}
