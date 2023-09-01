/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:57:44 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 12:06:05 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

const Fwoosh&	Fwoosh::operator= (const Fwoosh &fwoosh)
{
	if (this != &fwoosh)
	{
		this->m_name = fwoosh.m_name;
		this->m_effects = fwoosh.m_effects;
	}
	return (*this);
}

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{}

Fwoosh::~Fwoosh()
{}

Fwoosh*	Fwoosh::clone() const
{
	return (new Fwoosh());
}