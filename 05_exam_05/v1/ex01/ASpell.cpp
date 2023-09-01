/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:20:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 11:52:40 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell()
{}

ASpell::ASpell(const ASpell &other)
{
	*this = other;
}

const ASpell&	ASpell::operator= (const ASpell &aspel)
{
	if (this != &aspel)
	{
		m_name = aspel.m_name;
		m_effects = aspel.m_effects;
	}
	return (*this);
}

ASpell::ASpell(std::string name, std::string effects):
	m_name(name),
	m_effects(effects)
{}

ASpell::~ASpell()
{}

std::string		ASpell::getName() const
{
	return (m_name);
}

std::string		ASpell::getEffects() const
{
	return (m_effects);
}

void			ASpell::launch(const ATarget &target)
{
	target.getHitBySpell(*this);
}