/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:23:01 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 21:52:49 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim (name)
{
	std::cout	<< "Zog zog." 
				<< " (" << this << ")"
				<< std::endl;
}

Peon::~Peon()
{
	std::cout	<< "Bleuark..."
				<< " (" << this << ")"
				<< std::endl;
}

Peon::Peon(const Peon &other) : Victim (other)
{
	*this = other;
	std::cout	<< "Zog zog." 
				<< " (" << this << ")"
				<< std::endl;
}

std::ostream	&operator<< (std::ostream &out, const Peon &fix)
{
	out << fix.introduce();
	return (out);
}

void 		Peon::getPolymorphed() const
{
	std::cout	<< m_name
				<< " has been turned into a pink pony!"
				<< std::endl;
}