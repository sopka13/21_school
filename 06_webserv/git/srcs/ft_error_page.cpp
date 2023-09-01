/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_page.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 09:52:15 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:21:18 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

/*
** This get error_page from str
**	return (0) - Success
**	return (1) - Error
*/

int			ft_error_page(t_vars* vars, std::string &str)
{
#ifdef DEBUG
	std::cout << "ft_error_page start" << std::endl;
#endif
	// step 1: Init data
	std::string::iterator	start = str.begin();
	std::string				err_page_name;

	// step 2: Get file name
	while (str.length() && *start != ';')
	{
		if ((*start == ' ' || *start == '\t') && !err_page_name.length())
			continue;
		else if ((*start == ' ' || *start == '\t') && err_page_name.length())
		{
			std::cerr << "ERROR in config file: Error page name - faill" << std::endl;
			return (1);
		}
		err_page_name += *start;
		str.erase(start);
		start = str.begin();
	}

	// step 3: Trim ';' character from str_sum
	if (*start == ';')
		str.erase(start);

	// step 4: Check errors
	if(!(err_page_name.length()))
	{
		std::cerr << "ERROR in config file: Error page name - faill" << std::endl;
		return (1);
	}

	// step 5: Set global name
	vars->error_page = err_page_name;

#ifdef DEBUG
	std::cout << "ft_error_page end" << std::endl;
#endif
	return (0);
}
