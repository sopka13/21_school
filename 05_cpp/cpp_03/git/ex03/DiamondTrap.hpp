/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:43:29 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 08:07:32 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _DIAMONDTRAP_HPP_
#define _DIAMONDTRAP_HPP_

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	std::string			m_Name_d;
public:
	unsigned int	m_Hitpoints;
	unsigned int	m_Energy_points;
	unsigned int	m_Attack_damage;

	DiamondTrap(std::string name);
	~DiamondTrap();
	void	attack(std::string const & target);
	void	whoAmI();
};

#endif