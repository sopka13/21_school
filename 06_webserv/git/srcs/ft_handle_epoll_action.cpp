/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_epoll_action.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:13:43 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/31 22:33:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function execute 2 function depending on the type of descriptor 
*/

#include "../includes/headers.hpp"

void		ft_handle_epoll_action(t_vars *vars, int fd, uint32_t events)
{
	// 1. It's socket
	//	a. get fd
	//	b. create Resp_2
	//		1.1 need read
	//			a. read request
	//		1.2 need write
	//			a. write welcome_page/ send response
	//	c. add <fd, Resp_2> in container
	//	d. add fd in queue
	// 2. Isn't socket
	//	a. get Resp_2 from container
	//		2.1 need read
	//			a. read request
	//		2.2 need write
	//			a. write response
#ifdef DEBUG
	std::cout	<< "ft_handle_epoll_action start: fd = " << fd << std::endl;
#endif
	Response_2	*resp;

	// 1. It's socket
	for (int i = 0; i < static_cast<int>(vars->sockets->size()); ++i)
	{
		// std::cerr << "ITS socket ?							 fd = " << fd << "; socket = " << vars->sockets->operator[](i).getTcp_sockfd() << std::endl;
		if (fd == vars->sockets->operator[](i).getTcp_sockfd())
		{
			// step 1.1: Get fd
			vars->sockets->operator[](i).setFd();

			//	b. create Resp_2
			try
			{
				resp = new Response_2(&(vars->servers->operator[](i)), vars->sockets->operator[](i).getFd());
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
			if (events & EPOLLIN){	// need read
				// std::cerr << "Socket, need read" << std::endl;
				try {
					resp->readRequest();
				}
				catch(const std::exception& e) {
					std::cerr << e.what() << '\n';
					return ;
				}
			}
			else {					// need write
				// std::cerr << "Socket, need write" << std::endl;
				try {
					resp->sendResponse();
				}
				catch(const std::exception& e) {
					std::cerr << e.what() << '\n';
					return ;
				}
			}

			// if have unhandled request
			if (resp->getRequestContainerSize())
			{
				//	c. add <fd, Resp_2> in container
				vars->request_container->insert(std::pair<int, Response_2*>(vars->sockets->operator[](i).getFd(), resp));

				//	d. add fd in queue
				vars->ev.events = EPOLLIN | EPOLLOUT;
				vars->ev.data.fd = vars->sockets->operator[](i).getFd();
				if (epoll_ctl(vars->epoll_fd, EPOLL_CTL_ADD, vars->sockets->operator[](i).getFd(), &vars->ev) == -1)
				{
					std::cerr << "ERROR in ft_handle_epoll_action: Epoll_ctl add error" << std::endl;
					ft_exit(vars);
				}
			}
			return ;
		}
	}
	// 2. Isn't socket
	std::map<int, Response_2*>::iterator it = vars->request_container->find(fd);
	if (it != vars->request_container->end())
	{
		if (events & EPOLLIN)	// need read
		{
			// std::cerr << "Not socket, need read" << std::endl;
			try {
				it->second->readRequest();
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
				return ;
			}
		}
		else {					// need write
			// std::cerr << "Not socket, need write" << std::endl;
			try {
				it->second->sendResponse();
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
				return ;
			}
			
		}
	}
	else
	{
		std::cerr << "ERROR in ft_handle_epoll_action: FD missed" << std::endl;
	}

	// // step 1: Start handle function in thread
	// for (int i = 0; i < static_cast<int>(vars->sockets->size()); ++i)
	// {
	// 	// If it's socket
	// 	if (fd == vars->sockets->operator[](i).getTcp_sockfd())
	// 	{
	// 		// step 1.1: Set fd
	// 		vars->sockets->operator[](i).setFd();

	// 		// step 1.2: Get request and send response
	// 		try
	// 		{
	// 			// int ret = 0;
	// 			Response_2		resp(&(vars->servers->operator[](i)), vars->sockets->operator[](i).getFd());
	// 			resp.readRequest();
	// 			resp.sendResponse();
	// 			std::cerr << "!!!!!!!!!!!!!!!!!!1" << std::endl;
	// 			// if ((ret = resp.sendResponse()))
	// 			// {
	// 			// 	if (ret == 2)	// if close connection
	// 			// 	{
	// 			// 		close(vars->sockets->operator[](i).getFd());
	// 			// 		return ;
	// 			// 	}
	// 			// 	std::cerr << "ERROR ERROR in ft_handle_epoll_action: no unhandled request (or empty request) !!!" << std::endl;
	// 			// 	return ;
	// 			// }
	// 		}
	// 		catch(const std::exception& e)
	// 		{
	// 			std::cerr << e.what() << "2" << '\n';
	// 		}

	// 		// step 1.3: Add fd in epoll queue
	// 		vars->ev.events = EPOLLIN | EPOLLOUT;
	// 		vars->ev.data.fd = vars->sockets->operator[](i).getFd();
	// 		if (epoll_ctl(vars->epoll_fd, EPOLL_CTL_ADD, vars->sockets->operator[](i).getFd(), &vars->ev) == -1)
	// 		{
	// 			std::cerr << "ERROR in ft_handle_epoll_action: Epoll_ctl add error" << std::endl;
	// 			ft_exit(vars);
	// 		}

	// 		// step 1.4: Add socket number for fd for next handle
	// 		vars->fd_identify_socket->insert(std::pair<int, int>(vars->sockets->operator[](i).getFd(), i));

	// 		#ifdef DEBUG
	// 			std::cout	<< "ft_handle_epoll_action end: fd = " << fd << std::endl;
	// 		#endif
	// 		return ;
	// 	}
	// }

	// // step 2: If handle fd (no socket)
	// try
	// {
	// 	Response_2		resp(&(vars->servers->operator[](vars->fd_identify_socket->operator[](fd))), fd);
	// 	resp.readRequest();
	// 	// resp.sendResponse();
	// 	std::cerr << "!!!!!!!!!!!!!!!!!!2" << std::endl;
	// 	// if (resp.sendResponse())
	// 	// {
	// 	// 	std::cerr << "ERROR ERROR in ft_handle_epoll_action: no unhandled request !!!" << std::endl;
	// 	// 	return ;
	// 	// }
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	

	// if want new thread
	// step 2: Delete fd from queue epoll
	// if (epoll_ctl(vars->epoll_fd, EPOLL_CTL_DEL, fd, &vars->ev) == -1)
	// {
	// 	std::cerr << "ERROR in ft_handle_epoll_action: Epoll_ctl del error" << std::endl;
	// 	ft_exit(vars);
	// }
	// vars->threads.emplace_back(std::thread(ft_handle_epoll_fd, std::ref(vars), fd, -1));

#ifdef DEBUG
	std::cout	<< "ft_handle_epoll_action end: fd = " << fd << std::endl;
#endif
	return ;
}
