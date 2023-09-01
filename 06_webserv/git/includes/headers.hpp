/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:08:32 by eyohn             #+#    #+#             */
/*   Updated: 2021/11/28 14:41:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #define DEBUG 0
#define TEST 1

#define BUF_FOR_RESP 2048							// buff for response to client
#define DEF_ADR_CONF_FILE "./conf/webserv.conf"		// default config file
#define SEM_NAME_1 "sem_threads"
#define EPOLL_QUEUE_LEN 12							// epoll queue length
#define TIMER_FOR_LISTEN 0							// timeout for listen actions in milliseconds
#define WAIT_REQUEST_FROM_CLIENT_SEC 10				// timeout for request from client in second
#define WAIT_CLIENT_SEC 0							// timeout for monitoring request from client in second
#define WAIT_CLIENT_USEC 1							// timeout for monitoring request from client in microsecond


#include <iostream>
#include <fstream>			//ifstream
#include <sys/types.h>
#include <sys/socket.h>		//socket
#include <sys/sendfile.h>	//sendfile
#include <sys/epoll.h>		//epool
#include <sys/select.h>		//select
#include <sys/wait.h>		//waitpid
#include <sys/stat.h>		//stat
#include <netdb.h>			//gethostbyname
#include <stdlib.h>			//exit
#include <arpa/inet.h>		//inet_addr
#include <unistd.h>			//write
#include <errno.h>			//errno
#include <cstring>			//strerror
#include <map>				//map
#include <iterator>			//iterator
#include <deque>			//deque
#include <vector>			//vector
#include <string>
#include <algorithm>
#include <ctime>			//clock
#include <dirent.h>			//opendir
#include <fcntl.h>			//open
#include <unistd.h>			//dup2
#include <pthread.h>
#include <sstream>
// #include <stdlib.h>
// #include <semaphore.h>		//sem_open
// #include <csignal>
// #include <thread>
// #include <mutex>

class Socket;
class Server;
class Response;
class Response_2;

// extern	bool	exit_flag;				// exit flag for threads

typedef struct		s_args				// struct for thread
{
	int			fd;						// pipe
	int			tmp_file;				// output pile fd
	int			exit_flag;				// flag for stop read cycle
}					t_args;


typedef struct		s_request
{
	int				metod;
	int				version;
	std::string		host;
}					t_request;

typedef struct		s_socket
{
	int							tcp_sockfd;					// socket fd
	struct sockaddr_in			serv_addr;					// name for ipv4
	socklen_t					sock_len;					// length of serv_addr
}					t_socket;

typedef struct		s_location
{
	std::string					location_addr;				// local addr
	bool						autoindex;					// autoindex
	bool						redirect;					// redirect (on / off)
	std::string					redirect_adress;			// adress for redirect
	std::vector<std::string>	allowed_methods;			// methods
}					t_location;

typedef struct 		s_server
{
	std::string					ip;							// ip adress
	int							port;						// 1 : 65535
	std::vector<std::string>	server_name;				// server name
	std::vector<std::string>	index;						// name index files
	bool						default_server;				// default flag
	t_socket					sock_data;					// data for socket
	std::string					CGI_format;					// supported CGI format
	std::string					CGI_handler;				// handler for CGI scripts
}					t_server;

typedef struct		s_vars
{
	int							argc;
	char						**argv;
	char						**envp;
	std::ofstream				*log_file;					// logfile
	std::string					config_file_name;			// configuration file name
	std::string					CGI_file_name;				// CGI file name received from args
	std::map<std::string, std::string>	*CGI;				// supported CGI formats and handlers adresses
	std::string					max_body_size;				// client max body size
	int							ret;						// return value
	std::deque<Server>			*servers;					// all supported servers
	std::vector<Socket>			*sockets;					// all listen sockets
	// std::vector<std::thread>	threads;					// threads for servers
	// sem_t						*sema;						// semaphores
	// std::mutex					print_in_log;				// mutex for write in log file
	std::string					error_page;					// error page addr
	std::string					welcome_page;				// welcome page addr
	int							epoll_fd;					// epoll fd
	struct epoll_event			ev;							// struct for add fd in queue epoll
	struct epoll_event			events[EPOLL_QUEUE_LEN];	// output events from epoll
	// std::map<int, int>			*fd_identify_socket;		// container for identify socket by fd
	std::map<int, Response_2*>	*request_container;			// container for request from fd
}					t_vars;

extern t_vars* g_vars;

#include "../includes/Socket.hpp"
#include "../includes/Server.hpp"
#include "../includes/Response.hpp"
#include "../includes/Response_2.hpp"
#include "../includes/Headliners.hpp"


void		ft_bzero(void *s, size_t n);
int			ft_CGI_handler(t_vars* vars, std::string &str);
int			ft_check_args_files(t_vars *vars);
int			ft_client_max_body_size_handle(t_vars* vars, std::string &str);
int			ft_error_page(t_vars* vars, std::string &str);
void		ft_exit(t_vars *vars);
std::string	ft_get_name_conf(std::string &str);
void		ft_handle_epoll_action(t_vars *vars, int fd, uint32_t events);
void		ft_handle_epoll_fd(t_vars *vars, int fd, int i);
void		ft_handle_epoll_socket(t_vars *vars, int fd);
int			ft_http_handle(t_vars* vars, std::string &str);
void		ft_in_thread(t_vars &vars, int i);
void		ft_init_data(t_vars *vars, int argc, char** argv, char** envp);
int			ft_log_file_handle(t_vars* vars, std::string &str);
void		*ft_memset(void *s, int c, size_t n);
int			ft_parse_config(t_vars* vars);
int			ft_server_handle(t_vars* vars, std::string &str);
void		ft_signal_handler(int signal_num);
char		*ft_strcpy(char *dest, char *src);
size_t		ft_strlen(const char *s);
int			ft_strtrim(std::string &str, std::string chars);
int			ft_welcome_page(t_vars* vars, std::string &str);
void		ft_write_in_log_file(t_vars *vars, const char *str);
int			main(int argc, char **argv, char **envp);
