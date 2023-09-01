/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:54:24 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 20:17:58 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	bzero_character();
	m_name = "no_name";
}

Character::Character(std::string name)
{
	bzero_character();
	m_name = name;
}

Character::Character(const Character &other)
{
	m_name = other.m_name;
	free_character();
	bzero_character();
	for (int i = 0; i < MAX_INV; ++i)
	{
		if (other.m_inventory[i])
			m_inventory[i] = other.m_inventory[i]->clone();
	}
}

Character::~Character()
{
	free_character();
}

Character&	Character::operator= (const Character &fix)
{
	if (this == &fix)
		return (*this);

	m_name = fix.m_name;
	free_character();
	bzero_character();
	for (int i = 0; i < MAX_INV; ++i)
	{
		if (fix.m_inventory[i])
			m_inventory[i] = fix.m_inventory[i]->clone();
	}
	return (*this);
}

std::string const &	Character::getName() const
{
	return (m_name);
}

void		Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < MAX_INV; ++i)
	{
		if (m_inventory[i] == m)
			return ;
	}
	for (int i = 0; i < MAX_INV; ++i)
	{
		if (!m_inventory[i])
		{
			m_inventory[i] = m;
			break ;
		}
	}
	return ;
}

void		Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_INV)
		return ;
	for (int i = idx; i < MAX_INV; ++i)
	{
		if (i + 1 < MAX_INV)
		{
			m_inventory[i] = m_inventory[i + 1];
			continue ;
		}
		else
			m_inventory[i] = NULL;
	}
	return ;
}

void		Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_INV || !m_inventory[idx])
		return ;
	m_inventory[idx]->use(target);
	return ;
}

void		Character::free_character()
{
	for (int i = 0; i < MAX_INV; ++i)
	{
		if (m_inventory[i])
		{
			delete m_inventory[i];
			m_inventory[i] = NULL;
		}
	}
	return ;
}

void		Character::bzero_character()
{
	for (int i = 0; i < MAX_INV; ++i)
		m_inventory[i] = NULL;
	return ;
}