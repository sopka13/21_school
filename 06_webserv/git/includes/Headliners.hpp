/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headliners.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 08:53:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/01 20:36:03 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../includes/headers.hpp"

class Headliners
{
	std::string		_headliners;		// result headliners
	std::string		_end_headliners;	// \n\n
	Headliners();
public:
	Headliners(std::string http_version, std::string return_code);		// http_version ("HTTP/1.1")
																			// return_code ("200")
	~Headliners();

	std::string		getHeadliners();					// return result headliners
	void			setCloseConnection(bool);			// set Connection headliner true: keep-alive, false: close
	void			setContentLeigth(int);				// set Content-Leigth headliner
	void			setContentType(std::string);		// set Content-Type headliner
	void			setTransferEncoding();				// set Transfer-Encoding: chunked
	void			setSecretFlag(std::string);			// set x-secret-header-for-test
	void			sendHeadliners(int);				// send headliners in passed fd
	void			setAllowMethods(std::string types);	// set allowed methods
	std::string 	getAnswer(std::string str);
};