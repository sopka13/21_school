/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:03:36 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 15:02:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget()
{}

ATarget::ATarget(const std::string &type):
	m_type(type)
{}

ATarget::ATarget(const ATarget &other)
{
	*this = other;
}

ATarget::~ATarget()
{}

ATarget&			ATarget::operator= (const ATarget &atarget)
{
	if (this != &atarget)
		m_type = atarget.m_type;
	return (*this);
}

const std::string	ATarget::getType() const
{
	return (m_type);
}

void				ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout	<< this->getType()
				<< " has been "
				<< spell.getEffects()
				<< std::endl;
}