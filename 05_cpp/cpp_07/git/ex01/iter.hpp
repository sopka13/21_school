/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:33:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/03 01:47:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <iostream>

template <typename T1, typename T2>
void	iter(T1 *adress, T2 leigth, void (*f)(T1 const&))
{
	while(--leigth + 1)
		f(adress[leigth]);
	return ;
}

#endif
