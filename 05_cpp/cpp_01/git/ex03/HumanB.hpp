/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:27:25 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 17:25:14 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _HUMANB_HPP
#define _HUMANB_CPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	std::string	m_name;
	Weapon		*m_armor;
public:
	HumanB();
	HumanB(std::string name);
	void	attack();
	void	setWeapon(Weapon &arm);
};

#endif