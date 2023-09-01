/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:58:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/07 14:26:26 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
{
	m_name = name;
	m_apcost = apcost;
	m_damage = damage;
	
	std::cout	<< "AWeapon constructor start"
				<< " (" << this << ")" << std::endl;
}

AWeapon::~AWeapon()
{
	std::cout	<< "AWeapon destructor start"
				<< " (" << this << ")" << std::endl;
}

AWeapon::AWeapon(const AWeapon &other)
{
	*this = other;
	std::cout	<< "AWeapon copy constructor start"
				<< " (" << this << ")" << std::endl;
}

std::string const *AWeapon::getName() const
{
	return (&m_name);
}

int AWeapon::getAPCost() const
{
	return (m_apcost);
}

int AWeapon::getDamage() const
{
	return (m_damage);
}

AWeapon&	AWeapon::operator= (const AWeapon &aweapon)
{
	if (this == &aweapon)
		return (*this);
	
	m_damage = aweapon.m_damage;
	m_name = aweapon.m_name;
	m_apcost = aweapon.m_apcost;
	return (*this);
}

std::ostream &operator<< (std::ostream &out, const AWeapon &fix)
{
	out << fix.getName() << std::endl;
	return (out);
}