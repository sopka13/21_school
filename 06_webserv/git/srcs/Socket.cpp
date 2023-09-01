/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:48:29 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/01 21:45:16 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Socket.hpp"

//Socket::Socket(){};

Socket::Socket(Server *server):
	_server(server)
{
	int ret = 0;

	// step 1: Create socket
	_tcp_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (_tcp_sockfd < 0)
	{
		std::cerr << "ERROR opening socket 1: " << strerror(errno) << std::endl;
		return ;
	}

	ret = fcntl(_tcp_sockfd, F_SETFL, O_NONBLOCK);

	// step 2: Assigning a name to a socket
	ret = bind(_tcp_sockfd, (struct sockaddr *)(_server->getServAddr()), *_server->getSockLen());
	if (ret < 0)
	{
		std::string str = "ERROR Assigning name to a socket fail";
		throw Exeption(str);
	}
	// step 3: Create queue connection (очередь)
	ret = listen(_tcp_sockfd, SOMAXCONN);
	// if (vars->ret < 0)
	// {
	// 	std::cerr << "ERROR Listening fail: " << strerror(errno) << std::endl;
	// 	return (1);
	// }
	++ret; //без этого ругается компилятор
}

Socket::~Socket()
{}

// Socket::Socket(const Socket& soc){
// 	_sock_len = soc._sock_len;
// 	_serv_addr.sin_family = soc._serv_addr.sin_family;
// 	_serv_addr.sin_port = soc._serv_addr.sin_port;
// 	_serv_addr.sin_addr.s_addr = soc._serv_addr.sin_addr.s_addr;
// 	_tcp_sockfd = soc._tcp_sockfd;

	// int ret = bind(_tcp_sockfd, (struct sockaddr *)(&_serv_addr), _sock_len);
	// ret = listen(_tcp_sockfd, SOMAXCONN);
// }
// Socket& Socket::operator= (const Socket& soc){
// 	 _sock_len = soc._sock_len;
// 	_serv_addr.sin_family = soc._serv_addr.sin_family;
// 	_serv_addr.sin_port = soc._serv_addr.sin_port;
// 	_serv_addr.sin_addr.s_addr = soc._serv_addr.sin_addr.s_addr;
// 	_tcp_sockfd = soc._tcp_sockfd;
// 	return (*this);
// }


std::string		Socket::getLoc(std::string path)
{
	return(_server->getLocations(path));
}

int				Socket::getFd()
{
	return (_fd);
}

int				Socket::getTcp_sockfd()
{
	return (_tcp_sockfd);
}

void 			Socket::setFd()
{
	_fd = accept(_tcp_sockfd, (struct sockaddr *)(_server->getServAddr()), _server->getSockLen());
}
