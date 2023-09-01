/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:27:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 17:25:16 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _HUMANA_HPP_
#define _HUMANA_HPP_

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	std::string	m_name;
	Weapon		*m_armor;
public:
	HumanA();
	HumanA(std::string name, Weapon &arm);
	void	attack();
};

#endif