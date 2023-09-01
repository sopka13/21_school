/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:31:32 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/07 14:26:25 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type)
{
	m_hp = hp;
	m_type = type;
	std::cout	<< "Enemy constructor start"
				<< " (" << this << ")" << std::endl;
}

Enemy::~Enemy()
{
	std::cout	<< "Enemy destructor start"
				<< " (" << this << ")" << std::endl;
}

Enemy::Enemy(const Enemy &other)
{
	*this = other;
	std::cout	<< "Enemy copy constructor start"
				<< " (" << this << ")" << std::endl;
}

Enemy&	Enemy::operator= (const Enemy &enemy)
{
	if (this == &enemy)
		return (*this);
	
	m_hp = enemy.m_hp;
	m_type = enemy.m_type;
	return (*this);
}

std::string const	Enemy::getType() const
{
	return (m_type);
}

int		Enemy::getHP() const
{
	return (m_hp);
}

void	Enemy::takeDamage(unsigned int m)
{
	if (m > m_hp)
		m_hp = 0;
	else
		m_hp -= m;
	return ;
}

std::ostream &operator<< (std::ostream &out, const Enemy &fix)
{
	out	<< fix.getType() 
		<< " has "
		<< fix.getHP()
		<< " HP"
		<< std::endl;
	return (out);
}