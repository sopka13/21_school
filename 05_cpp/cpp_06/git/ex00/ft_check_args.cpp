/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:20:37 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/01 10:04:38 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

/*
**	Check args for validity
**		return (0) - Success
**		return (1) - Error
*/

int		ft_check_args(t_vars *vars)
{
	if (vars->argc != 2)
	{
		vars->num_err = 1;
		return (1);
	}
	return (0);
}