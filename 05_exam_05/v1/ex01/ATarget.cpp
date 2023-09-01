/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:31:28 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 12:45:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget()
{}

ATarget::ATarget(const ATarget &other)
{
	*this = other;
}

const ATarget&	ATarget::operator= (const ATarget &atarget)
{
	if (this != &atarget)
		m_type = atarget.m_type;
	return (*this);
}

ATarget::ATarget(std::string type):
	m_type(type)
{}

ATarget::~ATarget()
{}

const std::string&	ATarget::getType() const
{
	return (m_type);
}

void				ATarget::getHitBySpell(const ASpell &aspel) const
{
	std::cout	<< this->getType()
				<< " has been "
				<< aspel.getEffects()
				<< "!"
				<< std::endl;
}