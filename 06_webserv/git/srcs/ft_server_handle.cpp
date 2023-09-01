/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_handle.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:57:36 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:23:30 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function handle the server section
**	return (0) - Success
**	return (1) - Error
*/

// Need sorter servers for check single default server

#include "../includes/headers.hpp"

int			ft_server_handle(t_vars* vars, std::string &str)
{
#ifdef DEBUG
	std::cout << "ft_server_handle start: size servers = " << vars->servers->size() << std::endl;
#endif
	try
	{
		vars->servers->push_back(Server(str, vars));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

#ifdef DEBUG
	std::cout << "ft_server_handle end: size servers = " << vars->servers->size() << std::endl;
#endif
	return (0);
}
