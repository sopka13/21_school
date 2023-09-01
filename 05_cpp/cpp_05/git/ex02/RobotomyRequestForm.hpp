/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 20:58:56 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 15:04:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ROBOTOMYREQUESTFORM_HPP_
#define _ROBOTOMYREQUESTFORM_HPP_

#include <iostream>
#include <unistd.h>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	std::string		m_target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target = "No target");
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	const RobotomyRequestForm &operator= (const RobotomyRequestForm &president);
	std::string		getTarget() const;
	virtual void	execute(Bureaucrat const &executor) const;
};

#endif