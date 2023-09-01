/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response_2.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 08:56:56 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/02 10:04:52 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Response_2.hpp"

static std::string	ft_remove_underscore(std::string path, std::string title)
{
#ifdef DEBUG
	std::cerr	<< "ft_remove_underscore start: path = " << path << "; title = " << title << std::endl;
#endif
	while (path.size() && *(path.end() - 1) == '/')
		path.erase((path.end() - 1));
	while (title.size() && *(title.begin()) == '/')
		title.erase(title.begin());

#ifdef DEBUG
	std::cerr	<< "ft_remove_underscore end: result = " << path + '/' + title << std::endl;
#endif
	return (path + '/' + title);
}

static int			ft_check_have_data(std::string &data)
{
	for (int i = 0; i < static_cast<int>(data.size()); ++i)
	{
		if (data.operator[](i) != '\n' &&
			data.operator[](i) != '\r' &&
			data.operator[](i) != ' ' &&
			data.operator[](i) != '\0')
			return (1);
	}
	return (0);
}

static int			ft_search_end_header(std::string& temp)
{
	if (temp.find("\r\n\r\n", 0) != std::string::npos)
		return (0);
	return (1);
}

static void*		readCgiFromThread(void *args)
{
#ifdef DEBUG
	std::cerr	<< "readCgiFromThread start; " << std::endl;
#endif
	t_args			*arg = (t_args*) args;
	char			bufer[65000];
	int				ret = 65000;
	int				first_cycle = 0;

	while (arg->exit_flag)
	{
		ft_bzero(bufer, 65000);
		ret = read(arg->fd, bufer, 65000);
		if (!first_cycle)
		{
			int i = 0;
			while (i < ret)
			{
				if (bufer[i] == '\n' && i > 3 && bufer[i - 1] == '\r' && bufer[i - 2] == '\n' && bufer[i - 3] == '\r')
				{
					i++;
					int k = 0;
					char	tmp_buff[ret - i];
					while ((i + k) < ret)
					{
						tmp_buff[k] = bufer[i + k];
						k++;
					}
					tmp_buff[k] = '\0';
					write(arg->tmp_file, tmp_buff, k);
					break ;
				}
				i++;
			}
			first_cycle++;
			if (i < ret)
				continue ;
			// else if (i == ret)
			// 	break ;
			ret -= i;
		}
		write(arg->tmp_file, bufer, ret);
	}

#ifdef DEBUG
	std::cerr	<< "readCgiFromThread end; " << std::endl;
#endif
	return (arg);
}

Response_2::Response_2(Server *server, int fd):
	_server(server),
	_fd(fd),
	_close_flag(false),
	_requests()
{
#ifdef DEBUG
	std::cerr	<< "Response_2::Response_2 start: fd = " << _fd << std::endl;
#endif
	// step 1: Clear buff
	bzero(_buff, sizeof(_buff));

#ifdef DEBUG
	std::cerr	<< "Response_2::Response_2 end: fd = " << _fd << std::endl;
#endif
}

Response_2::~Response_2()
{
#ifdef DEBUG
	std::cerr	<< "Response_2::~Response_2 start: fd = " << _fd << std::endl;
#endif

#ifdef DEBUG
	std::cerr	<< "Response_2::~Response_2 end: fd = " << _fd << std::endl;
#endif
}

void				Response_2::getBlaCgiResult(Response *response, std::string full_path)
{
	// This function handle .bla CGI file
#ifdef DEBUG
	std::cerr	<< "Response_2::getBlaCgiResult start; " << std::endl;
#endif
	// step 1: Init data
	int			ret = 0;		// return value
	int			id;				// if child CGI script process
	int			pip[2];			// pipe for send body for script
	int			pop[2];			// pipe for send response from CGI
	std::string	flag = "HTTP_X_SECRET_HEADER_FOR_TEST=" + response->getSecretFlag();
	int			size_1 = flag.size();
	char		flg[size_1 + 1];

	// step 2: Create pipe
	if ((ret = pipe(pip)) == -1 || (ret = pipe(pop)) == -1)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);
		throw Exeption("ERROR in response_2: create pipe for CGI handlerr error");
	}
	// std::cerr << "step 2 ok" << std::endl;

	// step 3: Fork
	id = fork();
	// std::cerr << "step 3 ok" << std::endl;
	if (id == -1)			// error
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);
		throw Exeption("ERROR in response_2: create process for CGI handlerr error");
	}
	else if (id == 0)		// child
	{
		// step 3.1: Close pipe
		if ((ret = close(pip[1])) == -1 || (ret = close(pop[0])) == -1)
		{
			Headliners resp(std::string("HTTP/1.1"), std::string("500"));
			resp.sendHeadliners(_fd);
			throw Exeption("ERROR in response_2: close pipe[1] for CGI handlerr error");
		}
		// std::cerr << "step 3.1 ok" << std::endl;

		// step 3.2: Change fd
		if ((ret = dup2(pip[0], STDIN_FILENO)) == -1 || (ret = dup2(pop[1], STDOUT_FILENO)) == -1)
		{
			Headliners resp(std::string("HTTP/1.1"), std::string("500"));
			resp.sendHeadliners(_fd);
			throw Exeption("ERROR in response_2: close pipe[1] for CGI handlerr error");
		}
		// std::cerr << "step 3.2 ok" << std::endl;

		// step 3.3: Close fd
		close(pip[0]);
		close(pop[1]);
		// std::cerr << "step 3.3 ok" << std::endl;

		// step 3.4: Create env vars
		char*	argv[] = {
			NULL
		};
		std::vector<char *> envp;
		char	tmp2[] = "PATH_INFO=/home/sergey/My_prog/21_school/06_webserv/git/sites_avaliable/test/ubuntu_cgi_tester";
		envp.push_back(tmp2);
		char	tmp3[] = "REQUEST_METHOD=GET;POST";
		envp.push_back(tmp3);
		char	tmp4[] = "SERVER_PROTOCOL=HTTP/1.1";
		envp.push_back(tmp4);
		if ((response->getSecretFlag()).size())
		{
			int i;
			for (i = 0; i < size_1; ++i)
			{
				flg[i] = flag.operator[](i);
				std::cerr << "|" << flg[i];
			}
			std::cerr << std::endl;
			flg[i] = '\0';
			envp.push_back(flg);
		}
		envp.push_back(NULL);
		// std::cerr << "step 3.4 ok" << std::endl;

		// step 3.5: Execute script
		if ((ret = execve((_server->getCGI_handler()).c_str(), argv, &(*envp.begin()))))
		{
			Headliners resp(std::string("HTTP/1.1"), std::string("500"));
			resp.sendHeadliners(_fd);
			throw Exeption("ERROR in response_2: execute script error");
		}
	}

	// step 4: Close pipe
	if ((ret = close(pip[0])) == -1 || (ret = close(pop[1])) == -1)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);
		throw Exeption("ERROR in response_2: close pipe[0] for CGI handlerr error");
	}
	// std::cerr << "step 4 ok" << std::endl;

	// step 5: Create file for data from CGI
	std::string		file_name(full_path + ".temp");
	int				temp_file;
	if ((temp_file = open(file_name.c_str(), O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);
		throw Exeption("ERROR in response_2: create file for CGI handlerr error");
	}
	// std::cerr << "step 5 ok" << std::endl;

	// step 6: Create thread for read data from CGI
	pthread_t	readCgiThread;
	int			status_pthread;
	t_args		args;
	args.fd = pop[0];
	args.tmp_file = temp_file;
	args.exit_flag = 1;
	status_pthread = pthread_create(&readCgiThread, NULL, readCgiFromThread, &args);
	// std::cerr << "step 6 ok" << std::endl;


	// step 7: Send body
	int						offset = 0;
	int						size = (response->getBody()).size();
	int						size_part = 1000;

	while (offset < size)
	{
		if ((ret = write(pip[1],
						(response->getBody()).c_str() + offset,
						((offset + size_part) > size ? (size_part - (size - offset)) : size_part))) == -1)
		{
			Headliners resp(std::string("HTTP/1.1"), std::string("500"));
			resp.sendHeadliners(_fd);
			throw Exeption("ERROR in response_2: write in pipe for CGI handlerr error");
		}
		offset += ret;
	}
	// std::cerr << "step 7 ok" << std::endl;

	// step 8: Close pipe "EOF"
	if ((ret = close(pip[1])) == -1)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);
		throw Exeption("ERROR in response_2: close pipe for CGI handlerr error");
	}
	// std::cerr << "step 8 ok" << std::endl;

	// step 9: Wait child process and threads for read data from thread
	int		status;
	waitpid(id, &status, 0);
	args.exit_flag = 0;
	if ((ret = pthread_join(readCgiThread, (void**)&status_pthread)) != 0)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);
		throw Exeption("ERROR in response_2: pthread for read data from CGI error");
	}
	// std::cerr << "step 9 ok" << std::endl;

	// step 10: Close file and pipes
	if ((ret = close(temp_file)) == -1)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);
		throw Exeption("ERROR in response_2: close temp_file error");
	}
	close(pip[1]);
	close(pop[0]);
	// std::cerr << "step 10 ok" << std::endl;

	// step 11: Send file
	struct stat	info;
	stat(file_name.c_str(), &info);

	Headliners resp(std::string("HTTP/1.1"), std::string("200"));
	if (info.st_size < 35000)
		resp.setContentLeigth(info.st_size);
	else
		resp.setTransferEncoding();
	resp.setContentType("text/html; charset=utf-8");
	resp.setCloseConnection(false);
	resp.sendHeadliners(_fd);
	sendFile(file_name);
	// std::cerr << "step 11 ok" << std::endl;

	// step 12: delete temp file
	if (file_name.size() && file_name.find(".temp", 0) == (file_name.size() - 5))// && info.st_size < 10000000)
		remove(file_name.c_str());

#ifdef DEBUG
	std::cerr	<< "Response_2::getBlaCgiResult end" << std::endl;
#endif
	return ;
}

std::string			Response_2::setVariables(std::string &str)
{
	// Need handle getter vars from body. If have POST method with vars in body.
	size_t i = str.find("?");
	std::string var = "";
	if (i != std::string::npos){
		std::string::iterator it = str.begin();
		it += i + 1;
		while (it != str.end()){
			var += *it;
			++it;
		}
		str.erase(i, str.length());
	}
	return (var);
}

void				Response_2::sendFile(std::string full_path)
{
	// This function send file
#ifdef DEBUG
	std::cerr	<< "Response_2::sendFile start; path = " << full_path << std::endl;
#endif
	// step 1: Init data
	int		ret = 0;
	int		fd_from;

	// step 2: Get file_info
	struct stat	info;
	ret = stat(full_path.c_str(), &info);
	if (ret == -1)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);

		std::string str("ERROR in Response_2::sendFile: File not found");
		throw Exeption(str);
	}

	// step 3: Open file
	fd_from = open(full_path.c_str(), O_RDONLY);
	if (ret == -1)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);

		std::string str("ERROR in Response_2::sendFile: Open file error");
		throw Exeption(str);
	}

	// step 4: Send file
	off_t	offset = 0;
	ret = 1;
	char	temp_buf[32000];
	if (info.st_size < 32000)
	{
		if ((ret = sendfile(_fd, fd_from, &offset, info.st_size)) < 0)
		{
			if (epoll_ctl(_server->getEpollFd(), EPOLL_CTL_DEL, _fd, _server->getEpollEvent()) == -1)
				throw Exeption("ERROR in Response_2::readRequest: Epoll_ctl del error");
			Response_2* itt = (_server->getRequestContainerPointer())->operator[](_fd);
			(_server->getRequestContainerPointer())->operator[](_fd) = NULL;
			if ((ret = close(_fd)) == -1)
				std::cerr << "FAIL!!!" << std::endl;
			(_server->getRequestContainerPointer())->erase((_server->getRequestContainerPointer())->find(_fd));
			delete (itt);
			
			std::string strrr = "ERROR in sendfile: Send data error;";
			throw Exeption(strrr);
		}
	}
	else
	{
		while (ret > 0 && offset < info.st_size)
		{
			if (TEST)
				usleep(100);
			if ((ret = read(fd_from, temp_buf, 32000)) == -1)
			{
				std::cerr << "ERROR in sendfile: Read file for output error" << std::endl;
				break ;
			}
			else if (ret == 0)
			{
				std::cerr << "ERROR in sendfile: All data in file readed" << std::endl;
				break ;
			}
			else
			{
				int		rt = 0;
				offset += ret;
				std::stringstream stream;
				stream << std::hex << ret;
				std::string result(stream.str());

				if ((rt = send(_fd, result.c_str(), result.size(), 0)) == -1 ||
					(rt = send(_fd, "\r\n", 2, 0)) == -1 ||
					(rt = send(_fd, temp_buf, ret, 0)) == -1 ||
					(rt = send(_fd, "\r\n", 2, 0)) == -1)
				{
					if (epoll_ctl(_server->getEpollFd(), EPOLL_CTL_DEL, _fd, _server->getEpollEvent()) == -1)
						throw Exeption("ERROR in Response_2::readRequest: Epoll_ctl del error");
					Response_2* itt = (_server->getRequestContainerPointer())->operator[](_fd);
					(_server->getRequestContainerPointer())->operator[](_fd) = NULL;
					if ((ret = close(_fd)) == -1)
						std::cerr << "FAIL!!!" << std::endl;
					(_server->getRequestContainerPointer())->erase((_server->getRequestContainerPointer())->find(_fd));
					delete (itt);
					
					std::string strrr = "ERROR in sendfile: Send data error;";
					throw Exeption(strrr);
				}
				if ((rt = lseek(fd_from, offset, SEEK_SET)) == -1)
				{
					std::cerr << "ERROR in sendfile: lseek error" << std::endl;
					break ;
				}
			}
		}
		if ((ret = send(_fd, "0", 1, 0)) == -1 ||
			(ret = send(_fd, "\r\n", 2, 0)) == -1 ||
			(ret = send(_fd, "\r\n", 2, 0)) == -1)
		{
			if (epoll_ctl(_server->getEpollFd(), EPOLL_CTL_DEL, _fd, _server->getEpollEvent()) == -1)
				throw Exeption("ERROR in Response_2::readRequest: Epoll_ctl del error");
			Response_2* itt = (_server->getRequestContainerPointer())->operator[](_fd);
			(_server->getRequestContainerPointer())->operator[](_fd) = NULL;
			if ((ret = close(_fd)) == -1)
				std::cerr << "FAIL!!!" << std::endl;
			(_server->getRequestContainerPointer())->erase((_server->getRequestContainerPointer())->find(_fd));
			delete (itt);
			std::string strrr = "ERROR in sendfile: Send last data error";
			throw Exeption(strrr);
		}
		else
			std::cerr << "Sendfile ok; ret = " << ret << std::endl;
	}
	close(fd_from);

#ifdef DEBUG
	std::cerr	<< "Response_2::sendFile end; ret = " << offset << std::endl;
#endif
	return ;
}

void				Response_2::postHandle(Response *response)
{
	// This function handle POST method and has the following logic:
	// 	-- 0. if body size larger than the allowed one return error
	//	If have .bla go to getBlaCgiResult
	// 	1. if target_file doesn't exist
	// 		- create file and return 201 - created, or error if creation impossible
	// 	2. else
	// 		2.1. if target_file is a CGI:
	// 			a. get vars from body
	// 			b. execute CGI with received vars
	// 			c. send response 204 - if no content, 200 - if have content, or error if impossible
	// 		2.2. if target_file is not CGI but exist
	// 			a. If it's a directory
	// 				- create new file from body
	// 				- send response 201 - created, or error if creation impossible
	// 			b. If it's a file
	// 				- return 400 - Bad request
#ifdef DEBUG
	std::cerr	<< "Response_2::postHandle start" << std::endl;
#endif
	// step 1: Init data
	std::string		path(response->getPath());		// original path from request
	std::string		full_path;						// path with locations
	std::string		method("POST");
	int				ret = 0;
	_variables = setVariables(path);

	// step 2: Get full_path with locations
	std::string::iterator	end = path.end();
	std::string				temp;
	end--;
	while (path.size() && (_server->getLocations(path) == ""))
	{
		temp = full_path;
		full_path = *end;
		full_path += temp;
		path.erase(end);
		end--;
	}

	// step 3: Check error - if no path, and if have path get full_path with locations
	if (path == "")
	{
		struct stat	info;
		stat((_server->getErrPage()).c_str(), &info);

		Headliners resp(std::string("HTTP/1.1"), std::string("404"));
		resp.setCloseConnection(false);
		resp.setContentLeigth(info.st_size);
		resp.sendHeadliners(_fd);

		sendFile(_server->getErrPage());

		std::string str("ERROR in ft_post_handle: Bad path");
		throw Exeption(str);
	}
	else
	{
		// construct location + target_file name
		temp = ft_remove_underscore(_server->getLocations(path), full_path);
		full_path = temp;

		// check it's a dir or file
		struct stat		is_a_dir;
		ret = lstat(full_path.c_str(), &is_a_dir);

		if ((ret = lstat(full_path.c_str(), &is_a_dir)) != -1 && S_ISDIR(is_a_dir.st_mode))
		{
			temp = ft_remove_underscore(full_path, getIndexFileName(full_path)); // need upgrade if indexfile more than one
			full_path = temp;
		}
	}
	
	// step 4: If .bla
	if (haveCGI(full_path) && _server->getCGI_format() == ".bla")
	{
		getBlaCgiResult(response, full_path);
		return ;
	}

	// step 5: Check error - if method no supported
	if (!_server->getMethods(path, method)/* && !(haveCGI(temp_1) && _server->getCGI_format() == ".bla")*/)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("405"));
		resp.setAllowMethods(_server->getAllowMethods(path));
		resp.setCloseConnection(false);
		resp.setContentLeigth(0);
		resp.sendHeadliners(_fd);
		return ;
	}

	// step 6: Check target file/dir for exist
	struct stat	info;
	ret = stat(full_path.c_str(), &info);
	if (ret == -1)							//file/dir doesn't exist
	{
		// step 6.1: Create new file and write body
		std::ofstream	new_file(full_path.c_str());
		if (new_file.is_open())
		{
			new_file << response->getBody();
			new_file.close();
			ret = stat(full_path.c_str(), &info);

			// step 6.2: Send headliners
			Headliners resp(std::string("HTTP/1.1"), std::string("201"));
			resp.setContentLeigth(0);
			resp.setCloseConnection(false);
			resp.sendHeadliners(_fd);
		}
		else
		{
			// step 6.2: Send headliners
			Headliners resp(std::string("HTTP/1.1"), std::string("500"));
			resp.setContentLeigth(0);
			resp.setCloseConnection(false);
			resp.sendHeadliners(_fd);

			std::string str("ERROR in ft_post_handle: create target file error");
			throw Exeption(str);
		}
		return ;
	}
	else
	{
		if (haveCGI(full_path))				//target_file is a CGI
		{
			// step 7.1: Add body in vars
			_variables += response->getBody();

			// step 7.2: Execute CGI file
			std::string		target_file;
			target_file = handleCGI(full_path);

			// step 7.3: Send headliners
			struct stat	info_2;
			stat(target_file.c_str(), &info_2);
			if (info_2.st_size == 0)
			{
				Headliners resp(std::string("HTTP/1.1"), std::string("204"));
				resp.setCloseConnection(false);
				resp.setContentLeigth(0);
				resp.sendHeadliners(_fd);
			}
			else
			{
				Headliners resp(std::string("HTTP/1.1"), std::string("200"));
				resp.setCloseConnection(false);
				resp.setContentLeigth(info_2.st_size);
				resp.sendHeadliners(_fd);
			}
			// step 7.4: Send file
			std::cerr << "target_file = " << target_file << std::endl;
			sendFile(target_file);

			// step 7.5: Remove temp file
			if (target_file.size() && target_file.find(".temp", 0) == (target_file.size() - 5))
				remove(target_file.c_str());
			return ;
		}
		else								//target_file is not CGI
		{
			if (S_ISDIR(info.st_mode))	//it's a directory
			{
				// step 8.1: Check body_size. If body_size < max_body
				std::ofstream	new_file;
				if (_server->getMaxBodySize() >= static_cast<int>(response->getBodySize()))
				{
					// step 8.1.1: Create new file and write body
					std::string		new_file_name(ft_remove_underscore(full_path, std::string("new_file")));
					new_file.open(new_file_name.c_str());
					if (new_file.is_open())
					{
						new_file << response->getBody();
						new_file.close();
						
						Headliners resp(std::string("HTTP/1.1"), std::string("201"));
						resp.setContentLeigth(0);
						resp.setCloseConnection(false);
						resp.sendHeadliners(_fd);
					}
					else
					{
						Headliners resp(std::string("HTTP/1.1"), std::string("500"));
						resp.setContentLeigth(0);
						resp.setCloseConnection(false);
						resp.sendHeadliners(_fd);

						std::string str("ERROR in ft_post_handle: create temp file error");
						throw Exeption(str);
					}
				}
				// step 8.2: If body_size > max_body
				else
				{
					// step 8.2.1: Create new file and write body
					Headliners resp(std::string("HTTP/1.1"), std::string("413"));
					resp.setContentLeigth(0);
					resp.setCloseConnection(false);
					resp.sendHeadliners(_fd);
				}
				return ;
			}
			else		//it's a file
			{
				Headliners resp(std::string("HTTP/1.1"), std::string("400"));
				resp.setCloseConnection(false);
				resp.sendHeadliners(_fd);

				return ;
			}
		}
	}


#ifdef DEBUG
	std::cerr	<< "Response_2::postHandle end" << std::endl;
#endif
	return ;
}

int					Response_2::sendResponse()
{
#ifdef DEBUG
	std::cerr	<< "Response_2::sendResponse start: fd = " << _fd << "; size container = " << _requests.size() << std::endl;
#endif
	// step 1: Init data
	int						ret = 0;
	int						flag_405 = 0;
	std::string				path;
	std::string				tile;
	std::string::iterator	slesh;

	// step 2: If no unhandled request
	if (!_requests.size())
	{
		// have data monitoring only
		(_server->getEpollEvent())->events = EPOLLIN;
		(_server->getEpollEvent())->data.fd = _fd;
		ret = epoll_ctl(_server->getEpollFd(), EPOLL_CTL_MOD, _fd, _server->getEpollEvent());
		// std::cerr << "ret = " << ret << " err = " << errno << " fd = " << _fd << std::endl;
		return (0);
	}

	// step 3: Parse response
	int		flag = 0;
	try
	{
		Response response(_requests.operator[](0), _fd, _server->getMaxBodySize());
		flag = 1;
		_requests.pop_front();

		// step 4: If have close connection - return
		_close_flag = response.getClose();

		// step x: Handle POST method
		if (response.getMetod() == 2)
		{
			postHandle(&response);
			return (0);
		}

		// step 5: Write data for client
		path = response.getPath();
		_variables = setVariables(path);
		tile = "";
		slesh = path.end() - 1;
		while (_server->getLocations(path) == "" && path.length() > 1){
			while (*slesh != '/' && slesh != path.begin()){
				tile += *slesh;
				path.erase(slesh, path.end());
				--slesh;
			}
			if (path.length() > 1){
				tile += *slesh;
				path.erase(slesh, path.end());
				--slesh;
			}
		}

		// std::cout << "path = " << path << std::endl;
		if (_server->getRedirect(path)){
			// std::cout << "Ya tut" << std::endl;
			std::string str_of_redirect;
			str_of_redirect = "<head> \n<meta http-equiv=\"refresh\" content=\"1;URL=";
			str_of_redirect += _server->getRedirectAdress(path); 
			str_of_redirect += "\" />\n</head>";
			Headliners resp(std::string("HTTP/1.1"), std::string("301")); 
			resp.setCloseConnection(false);
			resp.setContentLeigth(str_of_redirect.size());
			resp.sendHeadliners(_fd);
			
			std::cout << "str_of_redirect = " << str_of_redirect << std::endl;
			if ((ret = send(_fd, str_of_redirect.c_str(), str_of_redirect.size(), 0)) < 0)
			{
				if (epoll_ctl(_server->getEpollFd(), EPOLL_CTL_DEL, _fd, _server->getEpollEvent()) == -1)
					throw Exeption("ERROR in Response_2::send response: Epoll_ctl del error");
				Response_2* itt = (_server->getRequestContainerPointer())->operator[](_fd);
				(_server->getRequestContainerPointer())->operator[](_fd) = NULL;
				if ((ret = close(_fd)) == -1)
					std::cerr << "FAIL!!!" << std::endl;
				(_server->getRequestContainerPointer())->erase((_server->getRequestContainerPointer())->find(_fd));
				delete (itt);
				
				std::string strrr = "ERROR in send response: Send data error;";
				throw Exeption(strrr);
			}
			// return (1);
		}
		
		std::reverse(tile.begin(), tile.end());
		std::string m = "GET";
		struct stat is_a_dir;
		if (response.getMetod() == 1 &&
			(_server->getLocations(path) != "") &&
			_server->getMethods(path, m))
		{
			std::string full_path = ft_remove_underscore(_server->getLocations(path), tile);
			ret = sendingResponseGet(&response, full_path, is_a_dir, path);
			flag_405 = 1;
		}

		m = "PUT";
		if (response.getMetod() == 3 &&
			(_server->getLocations(path) != "") &&
			_server->getMethods(path, m))
		{
			std::string full_path = ft_remove_underscore(_server->getLocations(path), tile);
			int i = lstat(full_path.c_str(), &is_a_dir);
			std::ofstream file;

			file.open(full_path.c_str());
			if (!file.is_open()){
				Headliners resp(std::string("HTTP/1.1"), std::string("500"));
				resp.sendHeadliners(_fd);
				return (-1);
			}
			file << response.getBody();
			file.close();
			std::string	buff_1 = response.getHttp(); 
			if (response.getBody() == ""){
				Headliners resp(std::string("HTTP/1.1"), std::string("204"));
				resp.sendHeadliners(_fd);
			}
				
			else if (i < 0){
				Headliners resp(std::string("HTTP/1.1"), std::string("201"));
				resp.setContentLeigth(0);
				resp.sendHeadliners(_fd);
			}
			else{
				Headliners resp(std::string("HTTP/1.1"), std::string("200"));
				resp.setContentLeigth(0);
				resp.sendHeadliners(_fd);
			}
			flag_405 = 1;
		}
		m = "DELETE";
		if (response.getMetod() == 4 &&
			(_server->getLocations(path) != "") &&
			_server->getMethods(path, m))
		{
			std::string full_path = ft_remove_underscore(_server->getLocations(path), tile);
			int rez = remove(full_path.c_str());
			if (rez >= 0){
				Headliners resp(std::string("HTTP/1.1"), std::string("200"));
				resp.sendHeadliners(_fd);
			}
			else {
				std::cerr << "rez " << rez << std::endl;
				Headliners resp(std::string("HTTP/1.1"), std::string("500"));
				resp.sendHeadliners(_fd);
			}
			flag_405 = 1;
		}
		if (flag_405 == 0)
		{
			Headliners resp(std::string("HTTP/1.1"), std::string("405"));
			resp.setAllowMethods(_server->getAllowMethods(path));
			resp.setCloseConnection(false);
			resp.setContentLeigth(0);
			resp.sendHeadliners(_fd);
		}
	}
	catch(const std::exception& e)
	{
		if (_requests.size() && flag == 0)
		{
			_requests.pop_front();
		}
		std::cerr << e.what() << '\n';
	}
	if (_close_flag)
	{
		if (epoll_ctl(_server->getEpollFd(), EPOLL_CTL_DEL, _fd, _server->getEpollEvent()) == -1)
			throw Exeption("ERROR in Response_2::readRequest: Epoll_ctl del error");
		Response_2* itt = (_server->getRequestContainerPointer())->operator[](_fd);
		(_server->getRequestContainerPointer())->operator[](_fd) = NULL;
		if ((ret = close(_fd)) == -1)
			std::cerr << "FAIL!!!" << std::endl;
		(_server->getRequestContainerPointer())->erase((_server->getRequestContainerPointer())->find(_fd));
		delete (itt);

		std::string str("ERROR in Response_2::sendFile: Closes connection flag");
		throw Exeption(str);
	}
	
#ifdef DEBUG
	std::cerr	<< "Response_2::sendResponse end: fd = " << _fd << "; size container = " << _requests.size() << std::endl;
#endif
	return (0);
}

void				Response_2::readRequest()
{
#ifdef DEBUG
	std::cerr	<< "Response_2::readRequest start: fd = " << _fd << "; size container = " << _requests.size() << std::endl;
#endif
	// step 1: Init data
	int				ret = 1;
	std::string		data;
	int				cycle = 1;
	// int				flag = 5;

	// step 2: Change fd mode
	fcntl(_fd, F_SETFL, O_NONBLOCK);

	// step 3: Cycle for read data from fd in _buff
	while (ret || cycle)
	{
		if (TEST)
			usleep(200);

		// step 3.1: Read
		ret = recv(_fd, _buff, sizeof(_buff), 0);

		// step x: If no data in chanel
		// if (ret <= 0 && data.size() == 0 && flag > 0)
		// {
		// 	usleep(100);
		// 	flag--;
		// 	continue ;
		// }

		// step 3.2: If first cycle and ret == 0
		if (ret <= 0 && data.size() == 0)
		{
			std::cerr << "EPOLLERR: fd = " << _fd << std::endl;
			if ((_server->getRequestContainerPointer())->size() &&
				(_server->getRequestContainerPointer())->find(_fd) != (_server->getRequestContainerPointer())->end())
			{
				if (epoll_ctl(_server->getEpollFd(), EPOLL_CTL_DEL, _fd, _server->getEpollEvent()) == -1)
					throw Exeption("ERROR in Response_2::readRequest: Epoll_ctl del error");
				Response_2* itt = (_server->getRequestContainerPointer())->operator[](_fd);
				(_server->getRequestContainerPointer())->operator[](_fd) = NULL;
				if ((ret = close(_fd)) == -1)
					std::cerr << "FAIL!!!" << std::endl;
				(_server->getRequestContainerPointer())->erase((_server->getRequestContainerPointer())->find(_fd));
				delete (itt);
			}

			break ;
		}

		// step 3.3: For search "\r\n\r\n"
		if (cycle)
			cycle = ft_search_end_header(data);

		// step 3.4: If no data
		if (ret <= 0 && cycle == 0)
			break ;

		// step 3.5: Add data in arr
		data += _buff;
		ft_bzero(&_buff, sizeof(_buff));
	}

	// step 4: Add request in container if have any data from fd
	if (data.size() && ft_check_have_data(data))
	{
		_requests.push_back(data);

		(_server->getEpollEvent())->events = EPOLLIN | EPOLLOUT;
		(_server->getEpollEvent())->data.fd = _fd;
		ret = epoll_ctl(_server->getEpollFd(), EPOLL_CTL_MOD, _fd, _server->getEpollEvent());
	}

	write(2, "###\n", 4);
	write(2, data.c_str(), (data.size() > 500 ? 500 : data.size()));
	write(2, "\n###\n", 6);

#ifdef DEBUG
	std::cerr	<< "Response_2::readRequest end: fd = "
				<< _fd
				<< "; size container = "
				<< _requests.size()
				<< "; cycle = "
				<< cycle
				<< std::endl;
#endif
	return ;
}

std::string			Response_2::ft_get_dir_list(std::string& full_path)
{
#ifdef DEBUG
	std::cerr	<< "Response_2::ft_get_dir_list start; full path = " << full_path << std::endl;
#endif
	// step 1: Init data
	DIR*			dirp;
	struct dirent*	dp;
	std::string		dir_content("<html>\n\t<body>\n");
	// std::cerr << "step 1 ok" << std::endl;


	// step 2: Construct html
	if ((dirp = opendir(full_path.c_str())))
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			// step x: If hidden file or dir
			if (dp->d_name[0] == '.')
				continue ;
			// step x: If dir
			else if (static_cast<int>(dp->d_type) == 4)
			{
				dir_content += "\t\t<p>";
				dir_content += dp->d_name;
				dir_content += '/';
				dir_content += "</p>\n";
			}
			else
			{
				dir_content += "\t\t<p>";
				dir_content += dp->d_name;
				dir_content += "</p>\n";
			}
		}
		(void)closedir(dirp);
	}
	else
	{
		dir_content += "\t\t<p>";
		dir_content += "Open target dir error";
		dir_content += "</p>\n";
	}
	dir_content += "\t</body>\n</html>\n";

	// step 3: Create file and write data
	std::ofstream	temp_file;
	std::string		cur_dir(full_path);
	cur_dir += "/dir_content.temp";
	temp_file.open(cur_dir.c_str(), std::ofstream::trunc);
	if (!temp_file.is_open())
	{
		std::cerr << "Strerror = " << strerror(errno) << "; errno = " << errno << std::endl;
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);
		throw Exeption("ERROR in response_2: create temp_file error!");
	}
	temp_file << dir_content;
	temp_file.close();

#ifdef DEBUG
	std::cerr	<< "Response_2::ft_get_dir_list end; cur_dir = " << cur_dir
				<< "; ret data = " << dir_content
				<< std::endl;
#endif
	return (cur_dir);
}

int					Response_2::sendingResponseGet(Response *response, std::string full_path, struct stat is_a_dir, std::string path)
{
#ifdef DEBUG
	std::cerr	<< "Response_2::sendingResponseGet start: fd = " << _fd << "; full path = " << full_path << std::endl;
#endif
	// step 1: Init data
	int ret;

	// step 2: Check it's file or dir
	ret = lstat(full_path.c_str(), &is_a_dir);
	std::string rezult_path;
	if (ret != -1 && S_ISDIR(is_a_dir.st_mode))
	{
		// step x: Add '/' character to the end of the line
		if (*(full_path.end() - 1) != '/')
			full_path += '/';

		// step 2.1: Get index file
		std::string index_name = getIndexFileName(full_path);

		// step 2.2: If index file is not specified
		if (index_name == "")
		{
			// step 2.2.1: Check autoindex
			if (!_server->getAutoindex(path))
			{
				// std::cerr << "this; " << path << "|" << std::endl;
				if (TEST)
				{
					struct stat	info;
					stat((_server->getErrPage()).c_str(), &info);

					Headliners resp(std::string("HTTP/1.1"), std::string("404"));
					resp.setCloseConnection(false);
					resp.setContentLeigth(info.st_size);
					resp.sendHeadliners(_fd);

					sendFile(_server->getErrPage());
				}
				else
				{
					Headliners resp(std::string("HTTP/1.1"), std::string("403")); 
					resp.sendHeadliners(_fd);
				}
				return (-1);
			}
			// step 2.2.2: If autoindex on - get directory list
			else
				rezult_path = ft_get_dir_list(full_path);
		}

		else
		{
			rezult_path = full_path + index_name;
			// std::cerr << "; full path 2 = " << full_path << std::endl;
		}
	}
	else
	{
		rezult_path = full_path;
		// std::cerr << "; full path 3 = " << full_path << std::endl;
	}

	// step 3: If have cgi go handle
	if (haveCGI(rezult_path) && _server->getCGI_format() != ".bla")// && !TEST)
		rezult_path = handleCGI(rezult_path);

	// step x: If have CGI .bla
	if (haveCGI(rezult_path) && _server->getCGI_format() == ".bla")
	{
		getBlaCgiResult(response, rezult_path);
		return (0);
	}
	
	// step x: Get info about target file
	struct stat	info;
	stat(rezult_path.c_str(), &info);

	// step 4: Open the requested file and read in buffer
	std::ifstream	fileIndex;

	// std::cerr << "result path 4 = " << rezult_path << std::endl;

	fileIndex.open(rezult_path.c_str());
	if (!fileIndex.is_open())
	{
		struct stat	info;
		stat((_server->getErrPage()).c_str(), &info);

		Headliners resp(std::string("HTTP/1.1"), std::string("404"));
		resp.setCloseConnection(false);
		resp.setContentLeigth(info.st_size);
		resp.sendHeadliners(_fd);

		sendFile(_server->getErrPage());

		std::cerr	<< "ERROR in sendingResponseGet: Target file open error" << std::endl;
		return (-1);
	}

	// step 5: Send headers "200 OK"
	Headliners resp(std::string("HTTP/1.1"), std::string("200"));
	resp.setCloseConnection(false);
	resp.setContentLeigth(info.st_size);
	resp.sendHeadliners(_fd);

	// step 6: Send body
	fileIndex.close();
	int		fd_from;
	if ((fd_from = open(rezult_path.c_str(), O_RDONLY)) == -1)
	{
		return (ret);
	}

	// std::cerr << "rezult_path = " << rezult_path << std::endl;
	if ((ret = sendfile(_fd, fd_from, NULL, info.st_size)) < 0)
	{
		if (epoll_ctl(_server->getEpollFd(), EPOLL_CTL_DEL, _fd, _server->getEpollEvent()) == -1)
			throw Exeption("ERROR in Response_2::sending response get: Epoll_ctl del error");
		Response_2* itt = (_server->getRequestContainerPointer())->operator[](_fd);
		(_server->getRequestContainerPointer())->operator[](_fd) = NULL;
		if ((ret = close(_fd)) == -1)
			std::cerr << "FAIL!!!" << std::endl;
		(_server->getRequestContainerPointer())->erase((_server->getRequestContainerPointer())->find(_fd));
		delete (itt);

		std::string str("ERROR in Response_2::sending response get: Closes connection flag");
		throw Exeption(str);
	}
	// std::string str;
	// while(std::getline(fileIndex, str))
	// {
	// 	ret = send(_fd, str.c_str(), str.length(), 0);
	// 	std::cerr << "send:" << ret << std::endl;
	// }
	
	// step x: Close file
	close(fd_from);

	// step 7: Remove temp file
	if (rezult_path.size() && rezult_path.find(".temp", 0) == (rezult_path.size() - 5))
		remove(rezult_path.c_str());

	// step 8: Close target file
	fileIndex.close();

#ifdef DEBUG
	std::cerr	<< "Response_2::sendingResponseGet end: rezult_path = " << rezult_path << std::endl;
#endif
	return (ret);
}

std::string			Response_2::getIndexFileName(std::string path)
{
#ifdef DEBUG
	std::cerr	<< "Response_2::getIndexFileName start: fd = " << _fd << std::endl;
#endif
	std::vector<std::string> ind = *(_server->getIndexName());
	std::string name;
	std::vector<std::string>::iterator n = ind.begin();
	while (n != ind.end()){
		name = *n;
		std::ifstream	file((path + name).c_str());
		if (file.is_open()){
			file.close();
			return (name);
		}
		++n;
	}

#ifdef DEBUG
	std::cerr	<< "Response_2::getIndexFileName end: fd = " << _fd << std::endl;
#endif
	return ("");
}

bool				Response_2::getCloseFlag()
{
	return (_close_flag);
}

int					Response_2::haveCGI(std::string &result_path)
{
#ifdef DEBUG
	std::cerr	<< "Response_2::haveCGI start; path = " << result_path << std::endl;
#endif
	// step 1: If CGI format not defined
	if (_server->getCGI_format() == "")
		return (0);

	// step 2: If str length enough and last chars compare CGI format
	if (result_path.size() > (_server->getCGI_format()).size() &&
		result_path.find(_server->getCGI_format(), 0) == (result_path.size() - (_server->getCGI_format()).size()))
		return (1);

#ifdef DEBUG
	std::cerr	<< "Response_2::haveCGI end" << std::endl;
#endif
	return (0);
}

std::string			Response_2::handleCGI(std::string &result_path)
{
#ifdef DEBUG
	std::cerr	<< "Response_2::handleCGI start; path = " << result_path << std::endl;
#endif
	// step 1: Init data

	// step 2: Create argv
	std::vector<char *>	argv;
	std::vector<char *>	envp;
	int					clear_numb = 0;

	// step 4: Add adress script_file in argv
	char		dir[100];
	getcwd(dir, 100);
	std::string cur_dir(dir);
	result_path.erase(0, 1);
	cur_dir += result_path;
	// cur_dir += '/';
	char *str = new char[cur_dir.size() + 1];
	std::copy(cur_dir.begin(), cur_dir.end(), str);
	str[cur_dir.size()] = '\0';
	// argv.push_back(str);

	// step 3: Add "-f" flag for php scripts
	char temp[] = "-f";
	if (_server->getCGI_format() == ".php" || _server->getCGI_format() == ".py")
	{
		// argv.push_back(temp);
		argv.push_back(temp);
		argv.push_back(str);
		clear_numb = 2;
		// argv.push_back(NULL);
	}
	else
	{
		argv.push_back(str);
		clear_numb = 1;
		// argv.push_back(NULL);
	}

	// step 5: Create envp and add env vars
	if (_variables.size())
	{
		std::string				temp;
		std::string::iterator	start = _variables.begin();
		std::string::iterator	end = _variables.end();
		while (start != end)
		{
			if (*start == '&' || start + 1 == end)
			{
				if (start + 1 == end && *start != '&')
					temp += *start;
				if (temp.size())
				{
					char *str_1 = new char[temp.size() + 1];
					std::copy(temp.begin(), temp.end(), str_1);
					str_1[temp.size()] = '\0';
					// envp.push_back(str_1);
					argv.push_back(str_1);
				}
				temp.clear();
				start++;
				continue ;
			}
			temp += *start;
			start++;
		}
		envp.push_back(NULL);
	}
	else
		envp.push_back(NULL);

	argv.push_back(NULL);

	// step 6: Construct file_name for result CGI handler
	std::string::iterator	end = cur_dir.end();
	end--;
	while (cur_dir.size() && *end != '.')
		cur_dir.erase(end--);
	cur_dir.erase(end);
	cur_dir += ".temp";

	// step 8: execute handler
	int		id = 0;
	id = fork();
	if (id == -1)
	{
		Headliners resp(std::string("HTTP/1.1"), std::string("500"));
		resp.sendHeadliners(_fd);
		throw Exeption("ERROR in response_2: create process for CGI handlerr error");
	}
	else if (id == 0)
	{
		// step x: Init data
		int ret = 0;
		FILE	*rek;

		// step x: Redirect stdout in file
		rek = freopen(cur_dir.c_str(), "w+", stdout);
		if (!rek)
		{
			Headliners resp(std::string("HTTP/1.1"), std::string("500"));
			resp.sendHeadliners(_fd);
			std::cerr	<< "ERROR CGI: Redirection stdout faill" << std::endl;
			exit(0);
		}

		// step x: Execute script
		if ((ret = execve((_server->getCGI_handler()).c_str(), &(*argv.begin()), &(*envp.begin()))) == -1)
		{
			Headliners resp(std::string("HTTP/1.1"), std::string("500"));
			resp.sendHeadliners(_fd);

			std::cerr	<< "ERROR CGI: execute CGI handler error" << std::endl;
		}

		// step x: If hane errors close and exit
		fclose(stdout);
		fclose(rek);
		exit(0);
	}

	// step 9: Wait child process
	int		status;
	waitpid(id, &status, 0);

	// step 10: Free memory
	delete[] str;
	for (int i = clear_numb; i < static_cast<int>(argv.size()); ++i)
		delete[] argv.operator[](i);

#ifdef DEBUG
	std::cerr	<< "Response_2::handleCGI end" << std::endl;
#endif
	return (cur_dir);
}

int					Response_2::getRequestContainerSize()
{
	return (_requests.size());
}
