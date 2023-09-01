/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:34:08 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/02 10:18:29 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _HEAD_HPP_
#define _HEAD_HPP_

#include <iostream>
#include <stdint.h>

struct		Data
{
	int		x;
	int		y;
};

uintptr_t	serialise(Data *ptr);
Data		*deserialise(uintptr_t raw);

#endif