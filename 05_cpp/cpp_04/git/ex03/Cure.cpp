/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:55:41 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 20:18:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria ("cure")
{}

Cure::~Cure()
{}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void			Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout	<< "* sheals "
				<< target.getName()
				<< "'s wounds *"
				<< std::endl;
}