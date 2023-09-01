/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:50:21 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _CURE_HPP_
#define _CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();

	AMateria*		clone() const;// override;
	void			use(ICharacter& target);// override;
};

#endif