/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:24:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 21:30:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name)
{
	m_name = name;
	std::cout	<< "Some random victim called "
				<< m_name
				<< " just appeared!"
				<< " (" << this << ")"
				<< std::endl;
}

Victim::~Victim()
{
	std::cout	<< "Victim "
				<< m_name
				<< " just died foe no apparent reason!"
				<< " (" << this << ")"
				<< std::endl;
}

Victim::Victim(const Victim &other)
{
	*this = other;
	std::cout	<< "Some random victim called "
				<< m_name
				<< " just appeared!"
				<< " (" << this << ")"
				<< std::endl;
}

Victim& Victim::operator = (const Victim &victim)
{
	if (this == &victim)
		return (*this);

	m_name = victim.m_name;
	return (*this);
}

std::string	Victim::introduce() const
{
	return ("I'm " +
			m_name +
			" and I like otters!" +
			'\n');
}

void Victim::getPolymorphed() const
{
	std::cout	<< m_name
				<< " has been turned into a cute little sheep!"
				<< std::endl;
}

std::ostream &operator<< (std::ostream &out, const Victim &fix)
{
	out << fix.introduce();
	return (out);
}