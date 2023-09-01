/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:36:29 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/01 09:50:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

void	ft_init_vars(t_vars *vars, int argc, char** argv)
{
	ft_bzero(vars, sizeof(t_vars));
	vars->argc = argc;
	vars->argv = argv;
}