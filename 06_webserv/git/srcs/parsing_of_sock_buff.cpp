/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_of_sock_buff.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:25:33 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:25:52 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

int getMetod(std::string sock_buff, t_request *req)
{
	if (sock_buff.compare(0, 3, "GET") == 0)
		req->metod = 1;
	else if (sock_buff.compare(0, 4, "POST") == 0)
		req->metod = 2;
	else if (sock_buff.compare(0, 4, "HEAD") == 0)
		req->metod = 3;
	else if (sock_buff.compare(0, 6, "DELETE") == 0)
		req->metod = 4;
	else
	 req->metod = 0;
	return (req->metod);
}

int parsing_of_sock_buff(char buff[BUF_FOR_RESP])
{
	t_request req;

	std::string sock_buff = static_cast<std::string>(buff);
	getMetod(sock_buff, &req);
	std::cout << "metod" << req.metod << std::endl;
	return (0);
}
