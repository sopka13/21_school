/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:13:23 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 10:37:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock()
{}

Warlock::Warlock(const Warlock &other)
{
	*this = other;
}

Warlock& Warlock::operator= (const Warlock &warlock)
{
	if (this != &warlock)
	{
		m_title = warlock.m_title;
		m_name = warlock.m_name;
	}
	return (*this);
}

Warlock::Warlock(const std::string & name, const std::string & title):
	m_name(name),
	m_title(title)
{
	std::cout	<< this->getName()
				<< ": This looks like another boring day."
				<< std::endl;
}

Warlock::~Warlock()
{
	std::cout	<< this->getName()
				<< ": My job here is done!"
				<< std::endl;
}

const std::string&	Warlock::getName() const
{
	return (m_name);
}

const std::string&	Warlock::getTitle() const
{
	return (m_title);
}

void				Warlock::setTitle(const std::string &new_title)
{
	m_title = new_title;
	return ;
}

void				Warlock::intriduce() const
{
	std::cout	<< this->getName()
				<< ": I am "
				<< this->getName()
				<< ", "
				<< this->getTitle()
				<< "!"
				<< std::endl;
}