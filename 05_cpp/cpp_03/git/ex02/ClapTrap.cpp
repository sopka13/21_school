/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:52:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 07:48:46 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	m_Hitpoints(10),
	m_Energy_points(10),
	m_Attack_damage(0)
{
	m_Name = "No name";
	std::cout	<< "ClapTrap constructor with name start"
				<< " Name: " << m_Name
				<< " Hitpoints: " << m_Hitpoints
				<< " Energy points: " << m_Energy_points
				<< " Attack damage: " << m_Attack_damage
				<< " (" << this << ")"
				<< std::endl;
}

ClapTrap::ClapTrap(std::string name):
	m_Hitpoints(10),
	m_Energy_points(10),
	m_Attack_damage(0)
{
	m_Name = name;
	std::cout	<< "ClapTrap constructor with name start"
				<< " Name: " << m_Name
				<< " Hitpoints: " << m_Hitpoints
				<< " Energy points: " << m_Energy_points
				<< " Attack damage: " << m_Attack_damage
				<< " (" << this << ")"
				<< std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout	<< "ClapTrap destructor start"
				<< " (" << this << ")"
				<< std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout	<< "ClapTrap " << m_Name
				<< " attacks " << target
				<< ", causing " << m_Attack_damage
				<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	m_Hitpoints -= amount;
	std::cout	<< "ClapTrap " << m_Name
				<< " get " << amount
				<< " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	m_Hitpoints += amount;
	std::cout	<< "ClapTrap " << m_Name
				<< " repare " << amount
				<< " hitpoints!" << std::endl;
}