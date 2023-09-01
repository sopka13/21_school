/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:26:14 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 13:57:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

// Intern::Intern(const Intern& other) {}

Intern::~Intern() {}

// const Intern& Intern::operator= (const Intern &intern) {}

Form*	Intern::makeForm(std::string name, std::string target)
{
	std::string	arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (Intern::*func[])(std::string) = {&Intern::create<ShrubberyCreationForm>,
											&Intern::create<RobotomyRequestForm>,
											&Intern::create<PresidentialPardonForm>};
	for (int i = 0; i < 3; ++i)
	{
		if (name == arr[i])
		{
			std::cout	<< "Intern creates "
						<< target
						<< std::endl;
			return ((this->*func[i])(target));
		}
	}
	std::cout	<< "This name form not found"
				<< std::endl;
	return (NULL);
}