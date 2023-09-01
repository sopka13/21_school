/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:09:05 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:10:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_di2(char *a, t_modify *modify)
{
	while ((modify->num2 > (int)ft_strlen(a) && modify->mns2 == 0) ||
			(modify->zero > 0 && modify->num1 > (int)ft_strlen(a) &&
			modify->num2 == 0 && modify->dot == 0 && modify->mns == 0) ||
			(modify->zero > 0 && modify->num1 > (int)ft_strlen(a) &&
			modify->num2 == 0 && modify->mns == 0 && modify->mns2 > 0))
		a = ft_strputst(a, '0');
	return (a);
}
