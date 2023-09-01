/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_CGI_handler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:26:58 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:20:29 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

static int	CGI_handler(std::string &str, std::string &handler_addr)
{
#ifdef DEBUG
	std::cout << "CGI_handler start: str = |" << str << "|" << std::endl;
#endif

	// step 1: Init data
	std::string::iterator	start = str.begin();

	// step 2: Get value
	while (str.length() && *start != ' ' && *start != '\t' && *start != ';')
	{
		handler_addr += *start;
		str.erase(start);
		start = str.begin();
	}

	// step 3: Trim spaces and tabs
	while (str.length() && (*start == ' ' || *start == '\t'))
	{
		str.erase(start);
		start = str.begin();
	}

	// step 4: Check errors and write data
	if (*start == ';')
		str.erase(start);
	else
	{
		std::cerr << "ERROR in CGI_handler: Error in config_file: ';' missed" << std::endl;
		return (1);
	}

#ifdef DEBUG
	std::cout << "CGI_handler end: handler_addr = " << handler_addr << std::endl;
#endif
	return (0);
}

int			ft_CGI_handler(t_vars* vars, std::string &str)
{
#ifdef DEBUG
	std::cout << "ft_CGI_handler start: str = |" << str << "|" << std::endl;
#endif
	std::map<std::string, int (*)(std::string&, std::string&)> functions;
	functions.insert(std::pair<std::string, int (*)(std::string&, std::string&)>("CGI_handler", CGI_handler));
	t_location				location_flags;
	location_flags.autoindex = false;
	location_flags.redirect = false;

	std::string::iterator	start = str.begin();
	std::string				temp;
	std::string				temp_key;
	std::string				handler_addr;
	int						i = 0;

	// step 1: Get first value
	while (str.length() && *start != ' ' && *start != '\t' && *start != '{')
	{
		temp_key += *start;
		str.erase(start);
		start = str.begin();
	}

	// step 2: Trim spaces and tabs
	while (str.length() && (*start == ' ' || *start == '\t'))
	{
		str.erase(start);
		start = str.begin();
	}

	// step 3: Set start value for get server section
	if (*start == '{')
	{
		i++;
		str.erase(start);
		start = str.begin();
	}
	else
	{
		std::cerr << "ERROR in CGI_handler: Error in config_file: empty block" << std::endl;
		return (1);
	}

	// step 4: Start write CGI section and trim '{' and '}' characters from the str_sum
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
		std::cerr << "ERROR in CGI_handler: Error in config_file: '{' or '}' missed" << std::endl;
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
		std::map<std::string, int (*)(std::string&, std::string&)>::iterator it = functions.find(ft_get_name_conf(temp));
		if (it != functions.end())
		{
			if ((*it->second)(temp, handler_addr))
				return (1);
		}
		else
		{
			std::cerr << "ERROR in ft_CGI_handler: Error in config_file" << std::endl;
			return (1);
		}
	}

	// step 4: Check error
	struct stat	temp_s;
	bzero(&temp_s, sizeof(temp_s));
	stat(handler_addr.c_str(), &temp_s);
	if (!temp_s.st_size)
	{
		std::cerr << "ERROR in ft_CGI_handler: Error in config_file: CGI handler not found" << std::endl;
		return (1);
	}

	vars->CGI->insert(std::pair<std::string, std::string>(temp_key, handler_addr));

#ifdef DEBUG
	std::cout << "ft_CGI_handler end: str = |" << str << "|" << std::endl;
#endif
	return (0);
}
