/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:52:23 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/04 11:47:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap	clap_1;
	ClapTrap	clap_2("Mone");

	clap_1.attack("Vici");
	clap_2.attack("Vici");
	clap_1.beRepaired(10);
	clap_2.beRepaired(100);
	clap_1.takeDamage(10);
	clap_2.takeDamage(10);

	return (0);
}