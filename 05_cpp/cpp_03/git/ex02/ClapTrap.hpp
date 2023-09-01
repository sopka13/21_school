/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:52:26 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 07:48:45 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _CLAPTRAP_HPP_
#define _CLAPTRAP_HPP_

#include <iostream>

class ClapTrap
{
protected:
	std::string		m_Name;
	unsigned int	m_Hitpoints;
	unsigned int	m_Energy_points;
	unsigned int	m_Attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif