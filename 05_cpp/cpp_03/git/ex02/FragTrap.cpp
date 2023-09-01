/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:01:32 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 09:53:42 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	ClapTrap::m_Hitpoints = 100;
	ClapTrap::m_Energy_points = 100;
	ClapTrap::m_Attack_damage = 30;
	std::cout	<< "FragTrap constructor start"
				<< " Name: " << m_Name
				<< " (" << this << ")"
				<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	ClapTrap::m_Hitpoints = 100;
	ClapTrap::m_Energy_points = 100;
	ClapTrap::m_Attack_damage = 30;
	std::cout	<< "FragTrap constructor start"
				<< " Name: " << name
				<< " (" << this << ")"
				<< std::endl;
}

FragTrap::~FragTrap()
{
	std::cout	<< "FragTrap destructor start"
				<< " (" << this << ")"
				<< std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout	<< "FragTrap high fives request"
				<< std::endl;
}