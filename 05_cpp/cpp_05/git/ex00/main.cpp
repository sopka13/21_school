/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:56:48 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/26 11:39:01 by eyohn            ###   ########.fr       */
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

	try {
		Bureaucrat	bur_2("Ken", 180);
		std::cout	<< bur_2;
	}
	catch(const std::exception& e){
		std::cout << e.what();
	}

	try {
		Bureaucrat	bur_4("Tera", -12);
		std::cout	<< bur_4;
	}
	catch(const std::exception& e){
		std::cout << e.what();
	}

	//Embedded function
	std::cout	<< bur;
	bur.incGrade();
	std::cout	<< bur;
	bur.decGrade();
	std::cout	<< bur;
	try {
		bur.decGrade();
	}
	catch(const std::exception& e){
		std::cout << e.what();
	}

	return (0);
}