/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:06:15 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/07 12:12:45 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("PlasmaRifle", 5, 21)
{
	std::cout	<< "PlasmaRifle constructor start"
				<< " (" << this << ")"
				<< std::endl;
}

PlasmaRifle::~PlasmaRifle()
{
	std::cout	<< "PlasmaRifle destructor start"
				<< " (" << this << ")"
				<< std::endl;
}

void	PlasmaRifle::attack() const
{
	std::cout	<< "* piouuu piouuu piouuu *"
				<< std::endl;
}