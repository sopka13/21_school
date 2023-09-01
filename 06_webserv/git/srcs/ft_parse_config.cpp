/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_config.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 08:37:55 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/17 22:41:47 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function parse config file and add data for socket
**	return (0) - Success
**	return (1) - Error
*/

#include "../includes/headers.hpp"

static void			ft_CGI_from_args(t_vars *vars, std::string &format)
{
#ifdef DEBUG
	std::cout	<< "ft_CGI_from_args start; format = " << format
				<< "; file name = " << vars->CGI_file_name
				<< std::endl;
#endif
	// step 1: Init data
	int					ret = 0;
	std::vector<char*>	argv;// = { NULL };
	std::vector<char*>	envp;
	envp.push_back(NULL);

	// step 2: Add file_name in argv
	char		dir[100];
	getcwd(dir, 100);
	std::string cur_dir(dir);
	cur_dir += '/';
	if (vars->CGI_file_name.operator[](0) == '.')
		vars->CGI_file_name.erase(0, 2);
	cur_dir += vars->CGI_file_name;
	char *str = new char[cur_dir.size() + 1];
	std::copy(cur_dir.begin(), cur_dir.end(), str);
	str[cur_dir.size()] = '\0';
	// argv.push_back(str);
	// std::cout << "str = " << str << std::endl;

	// step 3: Add "-f" flag for php scripts in argv
	char temp[] = "-f";
	if (format == ".py" || format == ".php")
	{
		argv.push_back(temp);
		argv.push_back(str);
		argv.push_back(NULL);
	}
	else
	{
		argv.push_back(str);
		argv.push_back(NULL);
	}

	// std::cerr << argv.operator[](0) << std::endl;

	// step x: Execute file
	if ((ret = execve((vars->CGI->operator[](format)).c_str(), &(*argv.begin()), &(*envp.begin()))) == -1)
	{
		// std::cout << strerror(errno) << " format = " << vars->CGI->operator[](format) << std::endl;
		std::cerr << "ERROR CGI: execute CGI handler error" << std::endl;
	}
	delete[] str;

#ifdef DEBUG
	std::cout	<< "ft_CGI_from_args end" << std::endl;
#endif
	return ;
}

static std::string	ft_get_format(std::string &file_name)
{
#ifdef DEBUG
	std::cout	<< "ft_get_format start" << std::endl;
#endif
	// step 1: Init data;
	std::string::iterator	start = file_name.begin();
	std::string::iterator	end = file_name.end();
	std::string				ret;

	// step 2: Check error
	if (file_name.find('.', 0) == std::string::npos)
		return ("");

	// step 3: Get format
	end--;
	while (end != start && *end != '.')
	{
		std::string temp("");
		temp += *end;
		temp += ret;
		ret = temp;
		end--;
	}
	if (*end == '.')
	{
		std::string temp("");
		temp += '.';
		temp += ret;
		ret = temp;
		end--;
	}

	// step 4: Check error
	if (end == start)
		return ("");

#ifdef DEBUG
	std::cout	<< "ft_get_format end; ret = " << ret << std::endl;
#endif
	return (ret);
}

int					ft_parse_config(t_vars *vars)
{
#ifdef DEBUG
	std::cout	<< "ft_parse_config start" << std::endl;
#endif
	// step 0: Check file get from args
	if (vars->argc == 2 || vars->argc == 3)
	{
		if (ft_check_args_files(vars))
			return (1);
	}
	else if (vars->argc > 3)
	{
		std::cerr	<< "ERROR: Too many args" << std::endl;
		return (1);
	}

	// step 1: Init data
	std::ifstream	configFile((vars->config_file_name.size()) ?
								(vars->config_file_name).c_str() : DEF_ADR_CONF_FILE);
	std::string		str;

	// step 2: Open config file
	if (!configFile.is_open())
	{
		std::cerr	<< "ERROR: Config file open error" << std::endl;
		return (1);
	}

	// step 3: Init data for read config file
	std::string		str_sum;
	std::map<std::string, int (*)(t_vars*, std::string&)> functions;
	functions.insert(std::pair<std::string, int (*)(t_vars*, std::string&)>("http", ft_http_handle));
	functions.insert(std::pair<std::string, int (*)(t_vars*, std::string&)>("log_file", ft_log_file_handle));
	functions.insert(std::pair<std::string, int (*)(t_vars*, std::string&)>("error_page", ft_error_page));
	functions.insert(std::pair<std::string, int (*)(t_vars*, std::string&)>("welcome_page", ft_welcome_page));
	functions.insert(std::pair<std::string, int (*)(t_vars*, std::string&)>("CGI", ft_CGI_handler));

	// step 4: Read config file in str_sum
	while(std::getline(configFile, str))
	{
		ft_strtrim(str, " \t\r\n");
		str_sum += str;
	}

	// step 5: Reserve memory for vector and map elements
	int i = 0;
	int pos = 0;
	for (int k = 0; k < static_cast<int>(str_sum.length()); ++k)
	{
		pos = str_sum.find("server {", k);
		if (pos > 0)
		{
			i++;
			k = pos;
		}
		else
			break ;
	}
	vars->sockets->reserve(i);

	// step 5: Get config name and execute handle functions
	while (str_sum.length())
	{
		if (str_sum[0] == ' ' || str_sum[0] == '\t')
		{
			str_sum.erase(0);
			continue ;
		}
		// need handle errors
		if ((*functions[ft_get_name_conf(str_sum)])(vars, str_sum))
			return (1);
	}

	// step 6: Close config file
	configFile.close();

	// step 7: Check errors in default server flags
	int k = 0;
	for (long unsigned int i = 0; i < vars->servers->size(); ++i)
	{
		if (vars->servers->operator[](i).getDefault())
			k++;
	}
	if (k > 1)
	{
		std::cerr	<< "ERROR: Config file contains more than one default server" << std::endl;
		return (1);
	}

	// step 8: Check CGI file_name for valid
	if (vars->CGI_file_name.size())
	{
		// step 8.1: Get file extension
		std::string		format_file;
		format_file = ft_get_format(vars->CGI_file_name);

		// step 8.2: Check error
		if (!format_file.size())
		{
			std::cerr	<< "ERROR: This file \"" << vars->CGI_file_name << "\" not supported" << std::endl;
			return (1);
		}

		// step 8.3: Search format file among the supported
		std::map<std::string, std::string>::iterator it = vars->CGI->find(format_file);
		if (it != vars->CGI->end())
		{
			ft_CGI_from_args(vars, format_file);
			return (1);
		}
		else
		{
			std::cerr	<< "ERROR: This file \"" << vars->CGI_file_name << "\" not supported" << std::endl;
			return (1);
		}
	}

#ifdef DEBUG
	std::cout	<< "ft_parse_config end" << std::endl;
#endif
	return (0);
}
