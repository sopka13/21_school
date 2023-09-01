/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:46:58 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 16:07:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

const Fireball&	Fireball::operator= (const Fireball &fireball)
{
	if (this != &fireball)
	{
		this->m_name = fireball.m_name;
		this->m_effects = fireball.m_effects;
	}
	return (*this);
}

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{}

Fireball::~Fireball()
{
	std::cout << "dtor Fireball" << std::endl;
}

Fireball*	Fireball::clone() const
{
	return (new Fireball());
}