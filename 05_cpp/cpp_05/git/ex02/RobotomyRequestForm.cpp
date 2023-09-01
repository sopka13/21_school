/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:23:09 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 15:04:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robot", 72, 45),
	m_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	Form(other),
	m_target(other.m_target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

const RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm &president)
{
	if (this != &president)
	{
		this->Form::operator=(president);
		this->m_target = president.m_target;
	}
	return (*this);
}

std::string		RobotomyRequestForm::getTarget() const
{
	return (m_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw FormNotSignedExeption();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowExeption();
	for (int i = 0; i < 3; ++i)
	{
		std::cout	<< "Drrr... " << std::endl;
		usleep(10);
	}
	srand(time(NULL));
	if ((rand() % 2 + 1) - 1)
	{
		std::cout	<< this->getTarget()
					<< " has been robotomized successfully 50% of the time"
					<< std::endl;
	}
	else
	{
		std::cout	<< this->getTarget()
					<< " has been robotomized failure"
					<< std::endl;
	}
	return ;
}