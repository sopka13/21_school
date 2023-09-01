/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headliners.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:00:15 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/01 20:36:06 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Headliners.hpp"

Headliners::Headliners(std::string http_version, std::string return_code):
	_headliners(http_version),
	_end_headliners("\n\n")
{
#ifdef DEBUG
	std::cout	<< "Headliners c_tor start: http_version = |" << http_version
				<< "| return_code = |" << return_code << "|"
				<< std::endl;
#endif
	std::map<std::string, std::string>	status_code;
	status_code.insert(std::pair<std::string, std::string>("100", " Continue"));
	status_code.insert(std::pair<std::string, std::string>("200", " OK"));
	status_code.insert(std::pair<std::string, std::string>("201", " Created"));
	status_code.insert(std::pair<std::string, std::string>("301", " Moved Permanently"));
	status_code.insert(std::pair<std::string, std::string>("204", " No Content"));
	status_code.insert(std::pair<std::string, std::string>("400", " Bad Request"));
	status_code.insert(std::pair<std::string, std::string>("403", " Forbidden"));
	status_code.insert(std::pair<std::string, std::string>("404", " Not Found"));
	status_code.insert(std::pair<std::string, std::string>("405", " Method Not Allowed"));
	status_code.insert(std::pair<std::string, std::string>("408", " Request Timeout"));
	status_code.insert(std::pair<std::string, std::string>("411", " Length Required"));
	status_code.insert(std::pair<std::string, std::string>("413", " Payload Too Large"));
	status_code.insert(std::pair<std::string, std::string>("500", " Internal Server Error"));
	status_code.insert(std::pair<std::string, std::string>("505", " HTTP Version Not Supported"));
	_headliners += ' ';
	_headliners += return_code;

	std::map<std::string, std::string>::iterator it = status_code.find(return_code);
	if (it != status_code.end())
		_headliners += status_code.operator[](return_code);
	else
		std::cerr << "ERROR in Headliners: This return_code not supported, need update Headliners class" << std::endl;

#ifdef DEBUG
	std::cout	<< "Headliners c_tor end: _headliners = |" << _headliners << "|"
				<< std::endl;
#endif
	return ;
}

Headliners::~Headliners()
{}

std::string		Headliners::getHeadliners()
{
	return (_headliners + _end_headliners);
}

void			Headliners::setCloseConnection(bool status)
{
	if (status)
		_headliners += "\nConnection: close";
	else
		_headliners += "\nConnection: keep_alive";
	return ;
}

void			Headliners::setContentLeigth(int length)
{
#ifdef DEBUG
	std::cout	<< "Headliners setContentLeigth start; length = " << length << std::endl;
#endif
	// step 1: Init data
	// char			str[32];
	std::string		temp("\nContent-length: ");
	char			size_size[32];

	sprintf(size_size, "%d", length);

	// int				size;
	// int				correct = 4;

	// // step 2: Get size constant part
	// size = length;				// size of body
	// size += _headliners.size();	// size other headliners
	// size += temp.size();		// size of this headliner
	// size += 2;					// "\n\n" between healiners and body
	// size += correct; 			// correct transfer
	// // std::cout << "step 2: size = " << size << std::endl;
	
	// // step 3: Get size number
	// bzero(str, sizeof(str));
	// sprintf(str, "%d", size);
	// int i;
	// for (i = 0; str[i] != '\0'; ++i)
	// 	size_size += str[i];
	// size += size_size.size();
	// // std::cout << "step 3: size = " << size << std::endl;

	// // step 4: Get full size
	// bzero(str, sizeof(str));
	// size_size.clear();
	// sprintf(str, "%d", size);
	// for (i = 0; str[i] != '\0'; ++i)
	// 	size_size += str[i];
	// while (size != (static_cast<int>(size_size.size()) +
	// 		2 + correct + static_cast<int>(temp.size()) + length +
	// 		static_cast<int>(_headliners.size())))
	// {
	// 	if (size < (static_cast<int>(size_size.size()) +
	// 				2 + static_cast<int>(temp.size()) + length +
	// 		static_cast<int>(_headliners.size())))
	// 		size++;
	// 	else
	// 		size--;
	// }
	// // std::cout << "step 4: size = " << size << std::endl;

	// // step 5: Create headliner
	// bzero(str, sizeof(str));
	// size_size.clear();
	// sprintf(str, "%d", size);
	// for (i = 0; str[i] != '\0'; ++i)
	// 	size_size += str[i];
	temp += size_size;
	// // std::cout << "step 5: size_size = " << size_size << std::endl;

	// step 6: Add headliner
	_headliners += temp;
	// std::cout << "step 6: size of headliners = " << _headliners.size() + 2 << std::endl;

#ifdef DEBUG
	std::cout	<< "Headliners setContentLeigth end; _headliners size = " << size_size << std::endl;
#endif
	return ;
}

void			Headliners::setContentType(std::string type)
{
	_headliners += "\nContent-Type: ";
	_headliners += type;
	return ;
}

void			Headliners::setAllowMethods(std::string types)
{
	_headliners += "\nAllow: ";
	_headliners += types;
	return ;
}

void			Headliners::setTransferEncoding()
{
	_headliners += "\nTransfer-Encoding: chunked";
	return ;
}

void			Headliners::setSecretFlag(std::string value)
{
	_headliners += "\nX-Secret-Header-For-Test: " + value;
	return ;
}

void			Headliners::sendHeadliners(int fd)
{
	std::string temp = getHeadliners();
	int	ret = 0;
	if ((ret = send(fd, temp.c_str(), temp.size(), 0)) == -1)
		throw "ERROR in headliners: send error";

	// std::cout << "send:" << ret << std::endl;
	std::cerr << "Headliners:\n" << getHeadliners();

	// if (_headliners.find("405", 0) != std::string::npos)
	// {
	// 	std::cerr << "Need NPOS P" << std::endl;
	// 	int	p;
	// 	std::cin >> p;
	// }

	// int	tfd;
	// tfd = open("./response", O_CREAT | O_APPEND | O_WRONLY, 0666);
	// write(tfd, getHeadliners().c_str(), getHeadliners().size());
	// write(tfd, "***\n", 5);
	// close(tfd);


	return ;
}

std::string		Headliners::getAnswer(std::string str){
	std::string::iterator	it = str.begin();
	int k = 0;
	while (it < str.end() && k < 4){
		if (*it == '\n' || *it == '\r')
			++k;
		++it;
	}
	str.erase(str.begin(), it);
	return(str);
}
