/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_welcome_handler.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:34:37 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:24:11 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

/*
** This get welcome_page from str
**	return (0) - Success
**	return (1) - Error
*/

int			ft_welcome_page(t_vars* vars, std::string &str)
{
#ifdef DEBUG
	std::cout << "ft_welcome_page start" << std::endl;
#endif
	// step 1: Init data
	std::string::iterator	start = str.begin();
	std::string				welcome_page_name;

	// step 2: Get file name
	while (str.length() && *start != ';')
	{
		if ((*start == ' ' || *start == '\t') && !welcome_page_name.length())
			continue;
		else if ((*start == ' ' || *start == '\t') && welcome_page_name.length())
		{
			std::cerr << "ERROR in config file: Welcome page name - faill" << std::endl;
			return (1);
		}
		welcome_page_name += *start;
		str.erase(start);
		start = str.begin();
	}

	// step 3: Trim ';' character from str_sum
	if (*start == ';')
		str.erase(start);

	// step 4: Check errors
	if(!(welcome_page_name.length()))
	{
		std::cerr << "ERROR in config file: Welcome page name - faill" << std::endl;
		return (1);
	}

	// step 5: Set global name
	vars->welcome_page = welcome_page_name;

#ifdef DEBUG
	std::cout << "ft_welcome_page end; welcome page path: " << vars->welcome_page << std::endl;
#endif
	return (0);
}
