/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:56:48 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 13:57:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	// Create obj
	Bureaucrat	bur("Ellis", 150);
	std::cout	<< bur;

	Bureaucrat	bur_3("Terminator", 1);
	std::cout	<< bur_3;

	PresidentialPardonForm	blank_1("Target_1");
	std::cout << blank_1 << std::endl;
	
	RobotomyRequestForm		blank_2("Target_2");
	std::cout << blank_2 << std::endl;

	ShrubberyCreationForm	blank_3("Target_3");
	std::cout << blank_3 << std::endl;

	//Sign form fail
	try {
		bur.signForm(blank_1);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur.signForm(blank_2);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur.signForm(blank_3);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}

	//Test execute form
	try {
		bur_3.executeForm(blank_1);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur_3.executeForm(blank_2);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur_3.executeForm(blank_3);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}

	//Sign form ok
	try {
		bur_3.signForm(blank_1);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur_3.signForm(blank_2);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur_3.signForm(blank_3);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}

	//Check signed form
	std::cout << blank_1 << std::endl;
	std::cout << blank_2 << std::endl;
	std::cout << blank_3 << std::endl;

	//Execute form fail
	try {
		bur.executeForm(blank_1);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur.executeForm(blank_2);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur.executeForm(blank_3);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}

	//Execute form ok
	try {
		bur_3.executeForm(blank_1);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur_3.executeForm(blank_2);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}
	try {
		bur_3.executeForm(blank_3);
	}
	catch(const std::exception& e) {
		std::cout << e.what();
	}

	//Intern
	Intern	fedya;
	Form	*new_form;

	new_form = fedya.makeForm("robotomy request", "First");
	std::cout << *new_form << std::endl;
	delete new_form;

	new_form = fedya.makeForm("shrubbery creation", "Second");
	std::cout << *new_form << std::endl;
	delete new_form;

	new_form = fedya.makeForm("presidential pardon", "Third");
	std::cout << *new_form << std::endl;
	delete new_form;
	
	new_form = fedya.makeForm("random form", "Fourth");

	return (0);
}