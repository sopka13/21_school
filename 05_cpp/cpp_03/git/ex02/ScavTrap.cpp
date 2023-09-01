/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:33:11 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 08:04:58 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	ClapTrap::m_Hitpoints = 100;
	ClapTrap::m_Energy_points = 50;
	ClapTrap::m_Attack_damage = 20;
	std::cout	<< "ScavTrap constructor with name start"
				<< " Name: " << m_Name
				<< " Hitpoints: " << m_Hitpoints
				<< " Energy points: " << m_Energy_points
				<< " Attack damage: " << m_Attack_damage
				<< " (" << this << ")"
				<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	ClapTrap::m_Hitpoints = 100;
	ClapTrap::m_Energy_points = 50;
	ClapTrap::m_Attack_damage = 20;
	std::cout	<< "ScavTrap constructor with name start"
				<< " Name: " << name
				<< " Hitpoints: " << m_Hitpoints
				<< " Energy points: " << m_Energy_points
				<< " Attack damage: " << m_Attack_damage
				<< " (" << this << ")"
				<< std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout	<< "ScavTrap destructor start"
				<< " (" << this << ")"
				<< std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout	<< "ScavTrap have enterred in Gate keeper mode"
				<< " (" << this << ")"
				<< std::endl;
}