/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:39:52 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/02 00:43:44 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int		main(int argc, char **argv)
{
	Karen	girl;
	std::map<std::string, int> lib = {
		{"DEBUG", 1},
		{"INFO", 2},
		{"WARNING", 3},
		{"ERROR", 4}
	};

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	switch (lib[argv[1]])
	{
	case 1:
		std::cout << "[DEBUG]" << std::endl;
		girl.complain("DEBUG");
		std::cout << std::endl;
	case 2:	
		std::cout << "[INFO]" << std::endl;
		girl.complain("INFO");
		std::cout << std::endl;
	case 3:
		std::cout << "[WARNING]" << std::endl;
		girl.complain("WARNING");
		std::cout << std::endl;
	case 4:
		std::cout << "[ERROR]" << std::endl;
		girl.complain("ERROR");
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	return (0);
}