/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:12:14 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 12:47:18 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title):
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

const std::string &Warlock::getName() const
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

void				Warlock::introduce() const
{
	std::cout	<< this->getName()
				<< ": I am "
				<< this->getName()
				<< ", "
				<< this->getTitle()
				<< "!"
				<< std::endl;
}
