/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:22:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:52 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Victim.hpp"

int		main(void)
{
	// Sorcerer	a("Ken", "I am goooood");
	// Sorcerer	b("Luka", "Impressive");

	// std::cout << a << std::endl;
	// std::cout << b << std::endl;

	// Victim		c("Lily");
	// Victim		d("Bob");

	// std::cout << c << std::endl;
	// std::cout << d << std::endl;

	// Peon		e("Ralf");
	// Peon		f("Ringer");

	// std::cout << e << std::endl;
	// std::cout << f << std::endl;

	Sorcerer	robert("Robert", "the Magnificent");

	Victim		jim("Jimmy");
	Peon		joe("Joe");

	std::cout	<< robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	return (0);
}