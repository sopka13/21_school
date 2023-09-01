/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:40:29 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/02 00:10:40 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _KAREN_HPP_
#define _KAREN_HPP_

#include <iostream>
#include <map>

class Karen
{
	typedef void (Karen::*Funk)(void);
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	std::map<std::string, Funk> ft =
	{
		{"DEBUG", &Karen::debug},
		{"INFO", &Karen::info},
		{"WARNING", &Karen::warning},
		{"ERROR", &Karen::error}
	};
public:
	void	complain( std::string level );
};

#endif