/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:17:59 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 13:57:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	template <typename T>
	Form*	create(std::string param)
	{
		return (new T(param));
	}
	Intern(const Intern& other);
	const Intern &operator= (const Intern &intern);

public:
	Intern();
	~Intern();

	Form*	makeForm(std::string name, std::string target);
};

#endif