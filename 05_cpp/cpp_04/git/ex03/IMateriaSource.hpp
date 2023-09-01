/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:43:43 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 20:18:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _IMATERIASOURCE_HPP_
#define _IMATERIASOURCE_HPP_

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {};
	virtual void LearnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif