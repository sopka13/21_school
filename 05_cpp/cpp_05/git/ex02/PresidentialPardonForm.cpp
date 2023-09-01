/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 20:15:01 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 10:16:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Freedom", 25, 5),
	m_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	Form(other),
	m_target(other.m_target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string		PresidentialPardonForm::getTarget() const
{
	return (m_target);
}

const PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &president)
{
	if (this != &president)
	{
		this->Form::operator=(president);
		this->m_target = president.m_target;
	}
	return (*this);
}
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw FormNotSignedExeption();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowExeption();
	std::cout	<< this->getTarget()
				<< " has been pardoned by Zafod Beeblebrox"
				<< std::endl;
	return ;
}