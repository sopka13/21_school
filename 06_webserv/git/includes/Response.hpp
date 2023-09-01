#ifndef RESPONSE_HPP
# define RESPONSE_HPP

#include "../includes/headers.hpp"
#include <cstddef>

class Response{
	int				_fd;				// client fd
	int				_maxBodySize;		// max body size
	int				_metod;				// request method
	std::string		_http;				// http version
	std::string		_path;				// path from request
	bool			_flag_connect;		// close connection
	std::string		_body;				// body
	size_t			_body_size;			// size of body
	size_t			_con_len;			// leigth of body
	bool			_flag_chunk;
	std::string		_secret_flag;		// x-secret-header-for-test
	Response();

public:
	class	Exeption : public std::runtime_error {
		public:
			Exeption(const std::string& message) : std::runtime_error(message) {}
	};
	Response(std::string &str, int fd, int maxBodySize);
	~Response();
	//Response(const Response& resp);
	//Response& operator= (const Response& resp);
	int				getMetod();
	std::string		getHttp();
	std::string		getPath();
	bool			getClose();
	std::string 	setBody(std::string& str);
	void 			setBodySize();
	std::string& 	getBody();
	size_t 			getBodySize();
	size_t 			getConLen();
	std::string		getSecretFlag();				// return secret flag
	std::string		body_chunk(std::string str);
};
#endif