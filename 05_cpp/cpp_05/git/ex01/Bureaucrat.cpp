/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:18:04 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 14:57:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	Bureaucrat::init_grade_arr()
{
	for(int i = 0; i < 150; ++i)
		this->m_value_grade[i] = i + 1;
	return ;
}

Bureaucrat::Bureaucrat():
	m_name("No_name")
{
	init_grade_arr();
	m_grade = m_value_grade[150 - 1];
	return ;
}

Bureaucrat::Bureaucrat(std::string name):
	m_name(name)
{
	init_grade_arr();
	m_grade = m_value_grade[150 - 1];
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	m_name(name)
{
	init_grade_arr();
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	m_grade = m_value_grade[grade - 1];
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	m_name(other.m_name),
	m_grade(other.m_grade)
{
	init_grade_arr();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat&		Bureaucrat::operator= (const Bureaucrat &bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);

	m_grade = bureaucrat.m_grade;
	return (*this);
}

std::string		Bureaucrat::getName() const
{
	return (m_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (m_grade);
}

void			Bureaucrat::incGrade()
{
	if (m_grade == 1)
		throw GradeTooHighException();
	m_grade--;
	return ;
}

void			Bureaucrat::decGrade()
{
	if (m_grade == 150)
		throw GradeTooLowException();
	m_grade++;
	return ;
}

void			Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout	<< this->getName()
					<< " sings "
					<< form.getName()
					<< std::endl;
	}
	catch (const std::exception& e) {
		std::cout	<< this->getName()
					<< " cannot sing "
					<< form.getName()
					<< " because "
					<< e.what()
					<< std::endl;
	}
}

std::ostream &operator<< (std::ostream &out, const Bureaucrat &fix)
{
	out	<< fix.getName()
		<< ", bureaucrat grade "
		<< fix.getGrade()
		<< std::endl;
	return (out);
}