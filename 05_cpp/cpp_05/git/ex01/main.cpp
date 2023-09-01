/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:56:48 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/26 17:05:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{
	// Create obj
	// try {
		Bureaucrat	bur("Ellis", 150);
		std::cout	<< bur;
	// }
	// catch(const std::exception& e){
	// 	std::cout << e.what();
	// }

	// try {
		Bureaucrat	bur_3("Terminator", 1);
		std::cout	<< bur_3;
	// }
	// catch(const std::exception& e){
	// 	std::cout << e.what();
	// }

	// try {
	// 	Bureaucrat	bur_2("Ken", 180);
	// 	std::cout	<< bur_2;
	// }
	// catch(const std::exception& e){
	// 	std::cout << e.what();
	// }

	// try {
	// 	Bureaucrat	bur_4("Tera", -12);
	// 	std::cout	<< bur_4;
	// }
	// catch(const std::exception& e){
	// 	std::cout << e.what();
	// }

	//Embedded function
	// std::cout	<< bur;
	// bur.incGrade();
	// std::cout	<< bur;
	// bur.decGrade();
	// std::cout	<< bur;
	// try {
	// 	bur.decGrade();
	// }
	// catch(const std::exception& e){
	// 	std::cout << e.what();
	// }

	// Form
	// try {
		Form	blank_1("Vedomost_1", 1, 1);
		std::cout << blank_1 << std::endl;
	// }
	// catch(const std::exception& e){
	// 	std::cout << e.what();
	// }
	try {
		Form	blank_2("Vedomost_2", 0, 0);
		std::cout << blank_2 << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what();
	}
	try {
		Form	blank_3("Vedomost_3", -2, 0);
		std::cout << blank_3 << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what();
	}
	try {
		Form	blank_4("Vedomost_4", 180, 1);
		std::cout << blank_4 << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what();
	}

	//Sign form
	try {
		std::cout	<< bur << std::endl;
		std::cout	<< blank_1 << std::endl;
		bur.signForm(blank_1);
	}
	catch(const std::exception& e){
		std::cout << e.what();
	}
	std::cout	<< blank_1 << std::endl;

	try {
		std::cout	<< bur_3 << std::endl;
		std::cout	<< blank_1 << std::endl;
		bur_3.signForm(blank_1);
	}
	catch(const std::exception& e){
		std::cout << e.what();
	}
	std::cout	<< blank_1 << std::endl;

	return (0);
}