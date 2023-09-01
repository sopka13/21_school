/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:49:20 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 16:07:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

const Polymorph&	Polymorph::operator= (const Polymorph &polymorph)
{
	if (this != &polymorph)
	{
		this->m_name = polymorph.m_name;
		this->m_effects = polymorph.m_effects;
	}
	return (*this);
}

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{}

Polymorph::~Polymorph()
{
	std::cout << "dtor Polymorph" << std::endl;
}

Polymorph*	Polymorph::clone() const
{
	return (new Polymorph());
}