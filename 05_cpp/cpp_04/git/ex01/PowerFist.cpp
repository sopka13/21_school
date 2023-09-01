/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:19:50 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/07 12:12:48 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("PowerFist", 8, 50)
{
	std::cout	<< "PowerFist constructor start"
				<< " (" << this << ")"
				<< std::endl;
}

PowerFist::~PowerFist()
{
	std::cout	<< "PowerFist destructor start"
				<< " (" << this << ")"
				<< std::endl;
}

void	PowerFist::attack() const
{
	std::cout	<< "* pschhh... SBAM! *"
				<< std::endl;
}