/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 08:02:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/25 21:09:07 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function init data for programm
*/

#include "../includes/headers.hpp"

void		ft_init_data(t_vars *vars, int argc, char** argv, char** envp)
{
#ifdef DEBUG
	std::cout << "ft_init_data start" << std::endl;
#endif
	// step 0: Check errors in header
	if (WAIT_CLIENT_USEC > 1000000 || WAIT_CLIENT_SEC >= WAIT_REQUEST_FROM_CLIENT_SEC)
	{
		std::cerr << "ERROR: timeouts in header have errors" << std::endl;
		ft_exit(vars);
	}

	// step 1: Clear struct
	ft_bzero(vars, sizeof(t_vars));
	// exit_flag = false;

	// step 2: argc, argv, envp
	vars->argc = argc;
	vars->argv = argv;
	vars->envp = envp;

	// step 3: Allocate memory
	vars->servers = new std::deque<Server>;
	vars->sockets = new std::vector<Socket>;
	// vars->fd_identify_socket = new std::map<int, int>;
	vars->request_container = new std::map<int, Response_2*>;
	vars->CGI = new std::map<std::string, std::string>;

	// step 4: Parse config file
	if (ft_parse_config(vars))
		ft_exit(vars);

	// step 5: Create semaphores for listen sockets
	// sem_unlink(SEM_NAME_1);
	
	// vars->sema = sem_open(SEM_NAME_1, 0100, 0666, vars->sockets->capacity());
	// if (vars->sema == SEM_FAILED)
	// {
	// 	std::cerr << "ERROR in ft_init_data: Semaphore create faill" << std::endl;
	// 	ft_exit(vars);
	// }

#ifdef DEBUG
	std::cout << "ft_init_data end" << std::endl;
#endif
	return ;
}
