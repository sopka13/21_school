/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log_file_handle.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:56:07 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:22:32 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

/*
** This get log_file_name from str and open it
**	return (0) - Success
**	return (1) - Error
*/

int			ft_log_file_handle(t_vars* vars, std::string &str)
{
#ifdef DEBUG
	std::cout << "ft_log_file_handle start" << std::endl;
#endif

	// step 1: Init data
	std::string::iterator	start = str.begin();
	std::string				log_file_name;

	// step 2: Get file name
	while (str.length() && *start != ';')
	{
		if (*start == ' ' || *start == '\t')
			continue;
		log_file_name += *start;
		str.erase(start);
		start = str.begin();
	}

	// step 3: Trim ';' character from str_sum
	if (*start == ';')
		str.erase(start);

	// step 4: Allocate memory for fstream object
	vars->log_file = new std::ofstream;
	vars->log_file->open(log_file_name.c_str(), std::ios::out | std::ios::app);

	// step 5: Check errors
	if(!(vars->log_file->is_open()))
	{
		std::cerr << "ERROR in config file: Logfile open error" << std::endl;
		return (1);
	}

#ifdef DEBUG
	std::cout << "ft_log_file_handle end" << std::endl;
#endif
	return (0);
}
