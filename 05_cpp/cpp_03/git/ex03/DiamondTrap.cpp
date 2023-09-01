/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:43:23 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 09:39:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	m_Hitpoints = FragTrap::m_Hitpoints;
	m_Energy_points = ScavTrap::m_Energy_points;
	m_Attack_damage = FragTrap::m_Attack_damage;
	m_Name_d = name;
	std::cout	<< "DiamondTrap constructor start"
				<< " Name: " << name
				<< " Hitpoints: " << m_Hitpoints
				<< " Energy points: " << m_Energy_points
				<< " Attack damage: " << m_Attack_damage
				<< " (" << this << ")"
				<< std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< "DiamondTrap destructor start"
				<< " (" << this << ")"
				<< std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	// std::clap_name = 
	std::cout	<< "DiamondTrap name: "
				<< m_Name_d
				<< " ClapTrap name: "
				<< this->m_Name
				<< " (" << this << ")"
				<< std::endl;
}