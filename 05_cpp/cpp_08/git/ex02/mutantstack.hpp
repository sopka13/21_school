/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 20:35:33 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/09 13:45:20 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _MUTANTSTACK_HPP_
#define _MUTANTSTACK_HPP_

#include <iostream>
#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){};

		MutantStack(const MutantStack & right) : std::stack<T>(right){};

		MutantStack & operator=(const MutantStack & right)
		{
			this->c = right.c;
			return (*this);
		}

		virtual ~MutantStack(){};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { return (this->c.begin()); };
		iterator end() { return (this->c.end()); };
};

#endif