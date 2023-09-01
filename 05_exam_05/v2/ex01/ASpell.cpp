/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:55:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 15:02:52 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell()
{}

ASpell::ASpell(const std::string &name, const std::string &effects):
	m_name(name),
	m_effects(effects)
{}

ASpell::ASpell(const ASpell &other)
{
	*this = other;
}

ASpell::~ASpell()
{}

ASpell&				ASpell::operator= (const ASpell &aspell)
{
	if (this != &aspell)
	{
		m_effects = aspell.m_effects;
		m_name = aspell.m_name;
	}
	return (*this);
}

const std::string&	ASpell::getName() const
{
	return (m_name);
}

const std::string&	ASpell::getEffects() const
{
	return (m_effects);
}

void				ASpell::launch(const ATarget& target)
{
	target.getHitBySpell(*this);
}