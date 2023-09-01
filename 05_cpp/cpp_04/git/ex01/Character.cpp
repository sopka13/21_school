/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:14:43 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 21:31:28 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name)
{
	m_name = name;
	m_AP = 40;
	m_weapon = NULL;
	std::cout	<< "Character constructor start"
				<< " (" << this << ")" << std::endl;
}

Character::Character(const Character &other)
{
	*this = other;
	std::cout	<< "Character copy constructor start"
				<< " (" << this << ")" << std::endl;
}

Character::~Character()
{
	std::cout	<< "Character destructor start"
				<< " (" << this << ")" << std::endl;
}

Character&	Character::operator= (const Character &character)
{
	if (this == &character)
		return (*this);

	m_AP = character.m_AP;
	m_name = character.m_name;
	m_weapon = character.m_weapon;
	return (*this);
}

void		Character::recoverAP()
{
	if ((m_AP + 10) < 40)
		m_AP += 10;
	else if (m_AP < 40)
		m_AP = 40;
	// else
	// 	;
	std::cout	<< m_name
				<< " recover Action points: AP = "
				<< m_AP
				<< std::endl;
	return ;
}

void		Character::equip(AWeapon *armor)
{
	m_weapon = armor;
	return ;
}

void		Character::attack(Enemy *enemy)
{
	if ((int)m_AP > m_weapon->getAPCost())
		m_AP -= m_weapon->getAPCost();
	else
	{
		std::cout	<< m_name
					<< " attack points are not enough !!!"
					<< " I need to recover! "
					<< std::endl;
	}
	std::cout	<< m_name
				<< " attacks "
				<< enemy->getType()
				<< " with a "
				<< *(m_weapon->getName())
				<< std::endl;
	if (m_weapon)
	{
		m_weapon->attack();
		enemy->takeDamage(m_weapon->getDamage());
		if (!enemy->getHP())
			enemy->~Enemy();
	}
	
	return ;
}

std::string const Character::getName() const
{
	return (m_name);
}

int Character::getAP() const
{
	return (m_AP);
}

std::string const *Character::getWeaponName() const
{
	if (m_weapon)
		return (m_weapon->getName());
	return (NULL);
}

std::ostream &operator<< (std::ostream &out, const Character &fix)
{
	std::string	temp = (fix.getWeaponName() ?
						("wields a " + *(fix.getWeaponName())) : "is unarmed");
	out	<< fix.getName()
		<< " has "
		<< fix.getAP()
		<< " AP and "
		<< temp
		<< std::endl;
	return (out);
}