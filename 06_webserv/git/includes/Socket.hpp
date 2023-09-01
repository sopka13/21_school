/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:48:19 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/01 21:45:07 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/headers.hpp"

class Socket{
public:
	// Socket();
	// Socket(t_vars *vars);
	// Socket(const Socket& soc);
	// Socket& operator= (const Socket& soc);
	Socket(Server *server);
	~Socket();
	int ft_handle_request();
	int getFd();
	void setFd();
	int getTcp_sockfd();
	std::string getLoc(std::string);

private:
	class	Exeption : public std::runtime_error {
		public:
			Exeption(const std::string& message) : std::runtime_error(message) {}
	};
	int						_tcp_sockfd;				// socket fd
	int						_fd;						// fd received after the acept call
	Server					*_server;					// data for server
};