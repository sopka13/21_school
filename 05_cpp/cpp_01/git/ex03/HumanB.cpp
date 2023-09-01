/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:27:28 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 17:25:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	m_name = "Noname";
	return ;
}

HumanB::HumanB(std::string name)
{
	m_name = name;
	return ;
}

void	HumanB::setWeapon(Weapon &arm)
{
	m_armor = &arm;
}

void	HumanB::attack()
{
	std::cout	<< m_name
				<< " attack with his "
				<< m_armor->getType()
				<< std::endl;
	return ;
}