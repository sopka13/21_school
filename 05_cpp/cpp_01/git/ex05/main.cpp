/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:39:52 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/02 00:10:40 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int		main(void)
{
	Karen	girl;

	girl.complain("DEBUG");
	girl.complain("INFO");
	girl.complain("WARNING");
	girl.complain("ERROR");
	return (0);
}