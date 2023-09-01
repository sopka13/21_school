/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:59:10 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:40:49 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Atoi for exit status (without handle more than one "+" and "-")
** long long int:
** -9223372036854775808 - min value
**  9223372036854775807 - max value
**  return (long long int) - Success
**  return (0) && vars->flags->error == 1 - Error
*/

#include "../minishell.h"

static int			ft_a(const char *arg, int i, long long int result, int neg)
{
	if ((arg[i + 1] && result > 922337203685477580 && neg == -1) ||
		(arg[i + 1] && arg[i + 1] == '9' && result == 922337203685477580 &&
		neg == -1) ||
		(arg[i + 1] && arg[i + 2] && result >= 922337203685477580) ||
		(arg[i + 1] && result >= 1000000000000000000) ||
		(arg[i + 1] && result > 922337203685477580 && neg == 1) ||
		(arg[i + 1] && arg[i + 1] == '8' && result == 922337203685477580 &&
		neg == 1))
		return (1);
	return (0);
}

long long int		ft_atoi_spec(t_vars *vars, const char *arg)
{
	int				i;
	int				neg;
	long long int	result;

	i = 0;
	neg = 1;
	result = 0;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i] == '-')
			neg = neg * (-1);
		i++;
	}
	while (arg[i] == '0')
		i++;
	while (arg[i] <= '9' && arg[i] >= '0')
	{
		result = result * 10 + arg[i] - '0';
		if (ft_a(arg, i++, result, neg))
		{
			vars->flags->error = 1;
			return (0);
		}
	}
	return (result * neg);
}
