/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:10:58 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 10:37:18 by eyohn            ###   ########.fr       */
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
	Warlock& operator= (const Warlock &warlock);
public:
	Warlock(const std::string & name, const std::string & title);
	~Warlock();
	
	const std::string&	getName() const;
	const std::string&	getTitle() const;
	void				setTitle(const std::string &new_title);
	void				intriduce() const;
};