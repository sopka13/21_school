/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:47:45 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _MATERIASOURCE_HPP_
#define _MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"
#define MAX_OBJ 4

class MateriaSource : public IMateriaSource
{
	AMateria		*m_objects[MAX_OBJ];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();// override;

	MateriaSource	&operator= (const MateriaSource &materiasource);
	void			LearnMateria(AMateria*);// override;
	AMateria*		createMateria(std::string const & type);// override;
	void			free_materia_source();
	void			bzero_materia_source();
};

#endif