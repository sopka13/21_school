/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:24:55 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 21:30:14 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
	m_name = name;
	m_title = title;

	std::cout	<< m_name
				<< ", "
				<< m_title
				<< ", is born!"
				<< " (" << this << ")"
				<< std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout	<< m_name
				<< ", "
				<< m_title
				<< ", is dead. Consequences will never be the same!"
				<< " (" << this << ")"
				<< std::endl;
}

Sorcerer& Sorcerer::operator = (const Sorcerer &sorcerer)
{
	if (this == &sorcerer)
		return (*this);
	
	m_name = sorcerer.m_name;
	m_title = sorcerer.m_title;
	return (*this);
}

Sorcerer::Sorcerer(const Sorcerer &other)
{
	*this = other;
	std::cout	<< m_name
				<< ", "
				<< m_title
				<< ", is born!"
				<< " (" << this << ")"
				<< std::endl;
}

std::string Sorcerer::introduce() const
{
	return ("I am " +
			m_name +
			", " +
			m_title +
			", and I like ponies!" +
			'\n');
}

void	Sorcerer::polymorph(Victim const &man) const
{
	man.getPolymorphed();
}

std::ostream &operator<< (std::ostream &out, const Sorcerer &fix)
{
	out << fix.introduce();
	return (out);
}