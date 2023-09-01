/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_name_conf.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:53:05 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:21:44 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

/*
** This function get name configure from str, trim it and return name_conf
*/

std::string	ft_get_name_conf(std::string &str)
{
#ifdef DEBUG
	std::cout << "ft_get_name_conf start: str = |" << str << "|" << std::endl;
#endif
	// step 0: Init data
	std::string::iterator	start = str.begin();
	std::string				name_conf;

	// step 1: Get name_conf
	while (str.length() && *start != ' ' && *start != '\t')
	{
		name_conf += *start;
		str.erase(start);
		start = str.begin();
	}

	// step 2: Erase spaces and tabs
	while (str.length() && (*start == ' ' || *start == '\t'))
	{
		str.erase(start);
		start = str.begin();
	}
#ifdef DEBUG
	std::cout << "ft_get_name_conf end: name = |" << name_conf << "| str: |" << str << "|" << std::endl;
#endif
	return (name_conf);
}
