/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaceuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:44:23 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 16:52:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_spaceuns(unsigned int x, char *a, t_modify *modify)
{
	if ((modify->space > 0 && modify->pls == 0 && x >= 0) ||
			(modify->space > 0 && modify->dot > 0 && modify->zero > 0 &&
			modify->pls == 0 && x >= 0))
		a = ft_strputst(a, ' ');
	if (x == 0 && modify->num2 == 0 && modify->dot > 0 &&
			modify->mns2 == 0)
		a = ft_strtrim(a, "0");
	while (modify->num1 > modify->num2 && modify->num1 > (int)ft_strlen(a))
	{
		if (modify->mns == 0)
			a = ft_strputst(a, ' ');
		else
			a = ft_strputend(a, ' ');
	}
	return (a);
}
