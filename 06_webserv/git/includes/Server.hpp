/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:29:47 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/01 22:05:10 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../includes/headers.hpp"

class Server
{
	t_server							server_data;
	std::map<std::string, t_location>	locations;			// locations
	t_vars								*_vars;
	// Server();
	// Server(const Server &other);
	// Server&	operator= (const Server &other);

public:
	class		Error : public std::exception {
		const char* what() const throw(){
			return ("ERROR in config file (server): Struct error");
		}
	};
	Server(std::string &str, t_vars *vars);
	~Server();

	const std::string*			getName(std::string &name) const;			// Return Name server compare geter
	const std::string*			getName() const;							// Return Name server
	const std::string&			getIp() const;								// Return ip adress
	int							getPort() const;							// Return port
	bool						getRedirect(std::string &);					// Return redirect
	std::string					getRedirectAdress(std::string &);			// Return redirect adress;
	bool						getAutoindex(std::string &);				// Return autoindex
	std::string					getLocations(std::string);					// Return locations
	socklen_t*					getSockLen();								// Return sock length
	sockaddr_in*				getServAddr();								// Return serv addr
	bool						getDefault();								// Return default or not
	const std::string&			getErrPage();								// Return err page address
	const std::string&			getWelcomePage();							// Return welcome page address
	bool						getMethods(std::string &, std::string &);	// Return allowed or not passed method for passed location key
	std::vector<std::string>*	getIndexName();								// Return iterator for indexfile vector
	const std::string&			getCGI_format();							// Return CGI format
	const std::string&			getCGI_handler();							// Return CGI handler
	int							getSockFd();								// Return socket fd
	int							getEpollFd();								// Return epoll fd
	struct epoll_event*			getEpollEvent();							// Return epoll event struct
	void						setSockFd(int);								// Set socket fd
	std::map<int, Response_2*>*	getRequestContainerPointer();				// Return pointer for request_container
	int							getMaxBodySize();							// Return max body size from config file
	std::string					getAllowMethods(std::string);				// Return allow methods
	// const std::string&			getFavicon();								// Return favicon.ico adress
};