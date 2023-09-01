/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:27:34 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 17:25:12 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _WEAPON_HPP_
#define _WEAPON_HPP

#include <iostream>

class Weapon
{
	std::string m_type;
public:
	Weapon();
	Weapon(std::string weapon_name);
	std::string	getType();
	void		setType(std::string name);
};

#endif