/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:27:35 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 17:25:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	m_type = "hand";
	return ;
}

Weapon::Weapon(std::string weapon_name)
{
	m_type = weapon_name;
	return ;
}

std::string	Weapon::getType()
{
	return (m_type);
}

void		Weapon::setType(std::string name)
{
	m_type = name;
	return ;
}