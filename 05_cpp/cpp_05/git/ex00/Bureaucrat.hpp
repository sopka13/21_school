/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:57:26 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/03 20:52:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>

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
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &fix);

#endif