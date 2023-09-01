/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:27:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 10:37:16 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

int		main(void)
{
	Warlock const richard("Richard", "Mistress of Magma");
	richard.intriduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;
	
	Warlock* jack = new Warlock("Jack", "the long");
	jack->intriduce();
	jack->setTitle("the Mighty");
	jack->intriduce();

	delete jack;

	return (0);
}