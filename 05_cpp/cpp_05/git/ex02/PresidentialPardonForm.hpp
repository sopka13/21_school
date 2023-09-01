/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 20:15:14 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/28 09:22:07 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _PRESIDENTIALPARDONFORM_HPP_
#define _PRESIDENTIALPARDONFORM_HPP_

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
	std::string		m_target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string target = "No target");
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	const PresidentialPardonForm &operator= (const PresidentialPardonForm &president);
	std::string		getTarget() const;
	virtual void	execute(Bureaucrat const &executor) const;
};

#endif