/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:41:22 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:53 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria():
	_type("no_name"),
	_xp(0)
{}


AMateria::AMateria(std::string const & type):
	_type(type),
	_xp(0)
{}

AMateria::AMateria(const AMateria &other):
	_type(other._type),
	_xp(other._xp)
{}

AMateria::~AMateria()
{}

AMateria&			AMateria::operator= (const AMateria &amateria)
{
	if (this == &amateria)
		return (*this);

	_type = amateria._type;
	_xp = amateria._xp;
	return (*this);
}

std::string const	& AMateria::getType() const			//Returns the materia type
{
	return (_type);
}

unsigned int		AMateria::getXP() const			//Returns the Materia's XP
{
	return (_xp);
}

void		AMateria::use(ICharacter& target)
{
	(void)target;
	_xp += 10;
}