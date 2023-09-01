/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:50:52 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include "ICharacter.hpp"
#include "AMateria.hpp"
#define MAX_INV 4

class Character : public ICharacter
{
private:
	AMateria		*m_inventory[MAX_INV];
	std::string		m_name;
public:
	Character();
	Character(std::string name);
	Character(const Character &other);
	~Character();

	Character			&operator= (const Character &fix);
	std::string const &	getName() const;// override;
	void				equip(AMateria* m);// override;
	void				unequip(int idx);// override;
	void				use(int idx, ICharacter& target);// override;
	void				free_character();
	void				bzero_character();
};

#endif