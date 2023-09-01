/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:52:23 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/06 07:33:09 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ClapTrap	clap_1;
	ScavTrap	scav_1;

	ClapTrap	clap_2("Mone");
	ScavTrap	scav_2("Vici");

	clap_1.attack("Vici");
	clap_2.attack("Vici");
	scav_1.attack("Mone");
	scav_2.attack("Mone");

	clap_1.beRepaired(10);
	clap_2.beRepaired(100);
	scav_1.beRepaired(10);
	scav_2.beRepaired(120);

	clap_1.takeDamage(10);
	clap_2.takeDamage(10);
	scav_1.takeDamage(10);
	scav_2.takeDamage(13);

	scav_1.guardGate();
	scav_2.guardGate();

	return (0);
}