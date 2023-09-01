/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_http_handle.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:54:41 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:22:18 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function set http settings from config_file
**	return (0) - Success
**	return (1) - Error
*/

#include "../includes/headers.hpp"

int			ft_http_handle(t_vars* vars, std::string &str)
{
#ifdef DEBUG
	std::cout << "ft_http_handle start: str = |" << str << "|" << std::endl;
#endif
	// step 0: Init data
	std::map<std::string, int (*)(t_vars*, std::string&)> functions;
	functions.insert(std::pair<std::string, int (*)(t_vars*, std::string&)>("client_max_body_size", ft_client_max_body_size_handle));
	functions.insert(std::pair<std::string, int (*)(t_vars*, std::string&)>("server", ft_server_handle));
	std::string::iterator	start = str.begin();
	std::string				temp;
	int						i = 0;

	// step 1: Set start value for get full section
	if (*start == '{')
	{
		i++;
		str.erase(start);
		start = str.begin();
	}
	else
	{
		std::cerr << "ERROR in config file (http): Struct error" << std::endl;
		return (1);
	}

	// step 2: start write http section and trim it from the str_sum
	while (i > 0 && str.length())
	{
		if (*start == '{')
			i++;
		if (*start == '}')
			i--;
		temp += *start;
		str.erase(start);
		start = str.begin();
	}
	if (i)
	{
		std::cerr << "ERROR in config file (http): Struct error" << std::endl;
		return (1);
	}
	else
	{
		std::string::iterator	end = temp.end();
		end--;
		temp.erase(end);
	}

	// step 3: start handle all settings from fttp section
	while (temp.length())
	{
		if (temp[0] == ' ' || temp[0] == '\t')
		{
			temp.erase(0);
			continue ;
		}
		if ((*functions[ft_get_name_conf(temp)])(vars, temp))
			return (1);
	}
#ifdef DEBUG
	std::cout << "ft_http_handle end: str = |" << str << "|" << std::endl;
#endif
	return (0);
}
