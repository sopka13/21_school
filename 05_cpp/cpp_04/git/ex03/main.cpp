/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:17:14 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 20:18:27 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int		main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->LearnMateria(new Ice());
	src->LearnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	ICharacter* loly = new Character("loly");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *loly);
	me->use(3, *loly);

	delete loly;
	delete bob;
	delete me;
	delete src;
	
	return 0;
}