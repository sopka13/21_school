/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:54:35 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 15:06:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
	m_name("No name"),
	m_sign(false),
	m_grade_sign(150),
	m_grade_exec(150)
{}

Form::Form(std::string name, unsigned int grade_sign, unsigned int grade_exec):
	m_name(name),
	m_sign(false),
	m_grade_sign(grade_sign),
	m_grade_exec(grade_exec)
{
	if (m_grade_sign > 150)
		throw GradeTooLowExeption();
	else if (m_grade_sign < 1)
		throw GradeTooHighExeption();
	else if (m_grade_exec > 150)
		throw GradeTooLowExeption();
	else if (m_grade_exec < 1)
		throw GradeTooHighExeption();
}

Form::Form(const Form& other):
	m_name(other.m_name),
	m_sign(other.m_sign),
	m_grade_sign(other.m_grade_sign),
	m_grade_exec(other.m_grade_exec)
{
	*this = other;
}

Form::~Form()
{}

Form&	Form::operator= (const Form &form)
{
	if (this != &form)
		m_sign = form.getSign();
	return (*this);
}

const std::string	Form::getName() const
{
	return (m_name);
}

bool	Form::getSign() const
{
	return (m_sign);
}

unsigned int	Form::getGradeSign() const
{
	return (m_grade_sign);
}

unsigned int	Form::getGradeExec() const
{
	return (m_grade_exec);
}

void	Form::beSigned(const Bureaucrat& human)
{
	if (human.getGrade() == m_grade_sign || human.getGrade() < m_grade_sign)
		m_sign = true;
	else
		throw GradeTooLowExeption();
	return ;
}

std::ostream&	operator<< (std::ostream &out, const Form &fix)
{
	out	<< "The form info:\n1) Name: \""
		<< fix.getName()
		<< "\";\n"
		<< "2) Signed: "
		<< (fix.getSign() ? "yes;\n" : "no;\n")
		<< "3) Grade for execute: "
		<< fix.getGradeExec()
		<< ";\n"
		<< "4) Grade for sign: "
		<< fix.getGradeSign()
		<< ";"
		<< std::endl;
	return (out);
}