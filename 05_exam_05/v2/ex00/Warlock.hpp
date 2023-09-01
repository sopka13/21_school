/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:10:23 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 12:47:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Warlock
{
	std::string		m_name;
	std::string		m_title;

	Warlock();
	Warlock(const Warlock &other);
	Warlock&	operator= (const Warlock &warlock);
public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock();

	const std::string	&getName() const;
	const std::string	&getTitle() const;
	void				setTitle(const std::string &new_title);
	void				introduce() const;
};