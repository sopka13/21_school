/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:02:24 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 20:18:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria ("ice")
{}

Ice::Ice(const Ice &other) : AMateria(other)
{}

Ice::~Ice()
{}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

Ice&	Ice::operator= (const Ice &fix)
{
	AMateria::operator=(fix);
	return (*this);
}

void			Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName()
				<< " *"
				<< std::endl;
}