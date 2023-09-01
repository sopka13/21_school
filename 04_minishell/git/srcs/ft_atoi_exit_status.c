/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_exit_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:15:22 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 12:36:37 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					ft_atoi_exit_status(t_vars *vars, char *arg)
{
	long long int	num;
	long long int	ret;

	ret = 256;
	if ((num = ft_atoi_spec(vars, arg)) == 0)
		return (0);
	while (num < 0)
	{
		if (ft_leigth_num(num) > 6)
		{
			ret = (ret * 2 > (-1 * num)) ? 256 : (ret * 2);
			num += ret;
		}
		num += 256;
	}
	while (num > 255)
	{
		if (ft_leigth_num(num) > 6)
		{
			ret = (ret * 2 > num) ? 256 : (ret * 2);
			num -= ret;
		}
		num -= 256;
	}
	return ((int)num);
}
