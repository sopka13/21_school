/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:50:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 14:59:38 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _FORM_HPP_
#define _FORM_HPP_

#define HIGH_LVL 1
#define LOW_LVL 150

class Bureaucrat;

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	const std::string	m_name;
	bool				m_sign;
	const unsigned int	m_grade_sign;
	const unsigned int	m_grade_exec;
	class GradeTooHighExeption : public std::exception {
		const char* what() const throw() {
			return ("Error: grade too high\n");
		}
	};
	class GradeTooLowExeption : public std::exception {
		const char* what() const throw() {
			return ("Error: grade too low\n");
		}
	};
	Form();

public:
	Form(std::string name = "No name", unsigned int grade_sign = 150, unsigned int grade_exec = 150);
	Form(const Form &other);
	~Form();

	Form&				operator= (const Form &form);
	const std::string	getName() const;
	bool				getSign() const;
	int					getGradeSign() const;
	int					getGradeExec() const;
	void				beSigned(const Bureaucrat &human);
};

std::ostream &operator<< (std::ostream &out, const Form &fix);

#endif