/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:34:08 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/02 11:34:27 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _HEAD_HPP_
#define _HEAD_HPP_

#include <iostream>
#include <stdlib.h>

class Base
{
public:
	Base() {};
	Base(const Base &other) {*this = other;};
	virtual ~Base() {};

	// const Base &operator= (const Base &base) {};
};

class A : public Base
{
public:
	A() {};
	A(const A &other) : Base(other) {};
	virtual ~A() {};

	// const A &operator= (const A &base) {};
};

class B : public Base
{
public:
	B() {};
	B(const B &other) : Base(other) {};
	virtual ~B() {};

	// const B &operator= (const B &base) {};
};

class C : public Base
{
public:
	C() {};
	C(const C &other) : Base(other) {};
	virtual ~C() {};

	// const C &operator= (const C &base) {};
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif