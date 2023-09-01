/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:52:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/07 14:26:20 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int		main(void)
{
	Character* me = new Character("me");
	std::cout << *me;

	Enemy* scorpion = new RadScorpion();
	Enemy* mutant = new SuperMutant();
	std::cout << *scorpion;
	std::cout << *mutant;

	AWeapon* plasma = new PlasmaRifle();
	AWeapon* power = new PowerFist();

	me->equip(plasma);
	std::cout << *me;

	me->attack(scorpion);
	std::cout << *me;
	std::cout << *scorpion;
	me->attack(mutant);
	std::cout << *me;
	std::cout << *mutant;

	me->equip(power);
	std::cout << *me;

	me->attack(scorpion);
	std::cout << *me;
	std::cout << *scorpion;
	me->attack(mutant);
	std::cout << *me;
	std::cout << *mutant;

	me->attack(scorpion);
	std::cout << *me;
	std::cout << *scorpion;

	delete me;
	delete scorpion;
	delete mutant;
	delete plasma;
	delete power;

	// Character* me = new Character("me");
	// std::cout << *me;
	// Enemy* b = new RadScorpion();
	// AWeapon* pr = new PlasmaRifle();
	// AWeapon* pf = new PowerFist();
	// me->equip(pr);
	// std::cout << *me;
	// me->equip(pf);
	// me->attack(b);
	// std::cout << *me;
	// me->equip(pr);
	// std::cout << *me;
	// me->attack(b);
	// std::cout << *me;
	// me->attack(b);
	// std::cout << *me;

	return (0);
}