/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:01:51 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ICE_HPP_
#define _ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	~Ice();

	Ice				&operator= (const Ice &fix);
	AMateria*		clone() const;// override;
	void			use(ICharacter& target);// override;
};

#endif