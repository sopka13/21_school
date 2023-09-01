/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:21:29 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 09:24:36 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

int		main(void)
{
	Warlock const richard("Richard", "Mistress of Magma");
	richard.introduce();
	std::cout <<richard.getName() << " - " << richard.getTitle() << std::endl;

	Warlock* jack = new Warlock("Jack", "the long");
	jack->introduce();
	jack->setTitle("The Mighty");
	jack->introduce();

	delete jack;

	return (0);
}