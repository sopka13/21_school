/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:57:26 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 15:03:16 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

class Form;

#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
	unsigned int		m_value_grade[150];
	void				init_grade_arr();
	const std::string	m_name;
	unsigned int		m_grade;
	class				GradeTooHighException : public std::exception {
			const char* what() const throw() {
				return ("Error: class too high\n");
			}
		};
	class				GradeTooLowException : public std::exception {
			const char* what() const throw() {
				return ("Error: class too low\n");
			}
		};
public:
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat		&operator= (const Bureaucrat &bureaucrat);
	std::string		getName() const;
	unsigned int	getGrade() const;
	void			incGrade();
	void			decGrade();
	void			signForm(Form &form);
	void			executeForm(Form const &form);
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &fix);

#endif