/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:38:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/02 16:06:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

void	ft_bzero(void *arr, size_t size)
{
	int		i;

	i = 0;
	while (i < static_cast<int>(size))
		*((unsigned char*)arr + i++) = 0x0;
	return ;
}