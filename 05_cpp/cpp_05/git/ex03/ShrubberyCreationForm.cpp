/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:34:33 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 13:24:00 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstring>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	Form("shrubbery creation", 145, 137),
	m_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	Form(other),
	m_target(other.m_target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &president)
{
	if (this != &president)
	{
		this->Form::operator=(president);
		this->m_target = president.m_target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw FormNotSignedExeption();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowExeption();
	std::ofstream file;
	std::string name = m_target + "_shrubbery";
	file.open(name.c_str());
	file << ASCII_TREE;
	file.close();
}