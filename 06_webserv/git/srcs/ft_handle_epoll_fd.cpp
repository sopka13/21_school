/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_epoll_fd.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:24:01 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:22:06 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function handle fd for response
*/

#include "../includes/headers.hpp"

void		ft_handle_epoll_fd(t_vars *vars, int fd, int i)
{
#ifdef DEBUG
	std::cout	<< "ft_handle_epoll_fd start: fd = "
				<< fd
				<< "; i = "
				<< i
				<< "; size server = "
				<< vars->servers->size()
				<< std::endl;
#endif
	// step 1: Init data
	Response_2		resp(&(vars->servers->operator[](i)), fd);
	int				k = clock();
	int				ret = 0;
	fd_set			rfd;
	fd_set			wfd;
	struct timeval	tv;
	tv.tv_sec = WAIT_CLIENT_SEC;
	tv.tv_usec = WAIT_CLIENT_USEC;
	// std::cout << "step 1 ok" << std::endl;

	// step 2: Handle first request
	resp.readRequest();
	resp.sendResponse();
	
	// step 3: create select
	while (((clock() - k) / CLOCKS_PER_SEC) < WAIT_REQUEST_FROM_CLIENT_SEC)
	{
		FD_ZERO(&rfd);
		FD_ZERO(&wfd);
		FD_SET(fd, &rfd);
		FD_SET(fd, &wfd);
		ret = select(1, &rfd, &wfd, 0, &tv);
		if (ret < 0)
		{
			std::cerr << "ERROR in ft_handle_epoll_fd: select fall" << std::endl;
			return ;
		}
		else if (ret == 0)
			continue ;
		else
		{
			k = clock();
			if (FD_ISSET(fd, &rfd))
			{
				resp.readRequest();
				continue;
			}
			if (FD_ISSET(fd, &wfd))
			{
				std::cout << "fine" << std::endl;
				if ((ret = resp.sendResponse()))
				{
					if (ret == 2)
					{
						close(fd);
						return ;
					}
					std::cerr << "NEED HANDLE ERROR: NO FREE REQUEST FROM CLIENT" << std::endl;
				}
			}
		}
	}
	close(fd);

	// step 4: Add fd in epoll queue
	// vars->ev.events = EPOLLIN | EPOLLOUT;
	// vars->ev.data.fd = fd;
	// if (epoll_ctl(vars->epoll_fd, EPOLL_CTL_ADD, fd, &vars->ev) == -1)
	// {
	// 	std::cout << "ERROR in ft_handle_epoll_fd: Epoll_ctl add error" << std::endl;
	// 	close(fd);
	// 	return ;
	// }
	// std::cout << "step 4 ok" << std::endl;

#ifdef DEBUG
	std::cout	<< "ft_handle_epoll_fd end: fd = " << fd << std::endl;
#endif
	return ;
}
