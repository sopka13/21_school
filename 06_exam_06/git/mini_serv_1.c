/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 08:54:22 by eyohn             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/02/11 21:21:46 by eyohn            ###   ########.fr       */
=======
/*   Updated: 2022/02/13 23:51:03 by eyohn            ###   ########.fr       */
>>>>>>> 15b9e967e367b8f5b50d4fff54b7a040f385160d
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <netinet/in.h>
#include <stdio.h>

typedef struct			s_clients {
	int					fd;
	int					id;
	struct s_clients*	next;
}						t_cli;

typedef struct			s_vars {
	fd_set				all_conn;
	fd_set				rfd;
	fd_set				wfd;
	fd_set				efd;
	uint16_t			port;
	struct sockaddr_in	servaddr;
	int					sock_fd;
	// buffer
	char				buff[42 * 4096];
	// id
	int					id;
	// clients queue
	t_cli*				clients;
}						t_vars;

void	ft_error(t_vars* vars, int status){
	write(2, "ft_error start\n", 16);
	t_cli*	temp = vars->clients;
	while (temp){
		t_cli* tmp = temp;
		temp = temp->next;
		free(tmp);
	}
	if (status)
		write(2, "Fatal error\n", 13);
	write(2, "ft_error end\n", 14);
	exit(status);
}

int		max_desc(t_vars *vars){
	write(2, "max_desc start\n", 16);
	int ret = vars->sock_fd;
	t_cli	*temp = vars->clients;

	while(temp){
		printf("Iteration fd = %d\n", temp->fd);
		if (temp->fd > ret)
			ret = temp->fd;
		temp = temp->next;
	}

	printf("ret value = %d\n", ret);
	write(2, "max_desc end\n", 14);
	return ret;
}

int		ft_start_prepare(t_vars *vars, char **argv){
	write(2, "ft_start_prepare start\n", 24);
	// Prepare data for server
	// return (1) - Error in system calls
	// return (0) - Fine
	FD_ZERO(&vars->all_conn);
	FD_ZERO(&vars->rfd);
	FD_ZERO(&vars->wfd);
	FD_ZERO(&vars->efd);
	vars->sock_fd = 0;
	vars->port = atoi(argv[1]);
	bzero(&vars->servaddr, sizeof(vars->servaddr));
	vars->servaddr.sin_family = AF_INET;
	vars->servaddr.sin_addr.s_addr = htonl(2130706433);
	vars->servaddr.sin_port = htons(vars->port);
	if ((vars->sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return 1;
	if ((bind(vars->sock_fd, (const struct sockaddr *)&vars->servaddr, sizeof(vars->servaddr))) < 0)
		return 1;
	if (listen(vars->sock_fd, 0))
		return 1;
	FD_SET(vars->sock_fd, &vars->all_conn);

	bzero(&vars->buff, sizeof(vars->buff));
	vars->id = 0;

	vars->clients = NULL;
	write(2, "ft_start_prepare end\n", 22);
	return 0;
}

int		ft_send_all(int fd, t_vars *vars){
	write(2, "ft_send_all start\n", 19);
	// Send buffer all clietns and clean buffer
	t_cli *temp = vars->clients;
	
	while (temp){
		if (temp->fd != fd && FD_ISSET(temp->fd, &vars->wfd)){
			int i = send(temp->fd, vars->buff, strlen(vars->buff), 0);
			printf("Send %d bytes\n", i);
			if (i < 0)
				return 1;
		}
		temp = temp->next;
	}
	bzero(&vars->buff, sizeof(vars->buff));

	write(2, "ft_send_all end\n", 17);
	return 0;
}

int		ft_add_client(t_vars *vars, int fd){
	write(2, "ft_add_client start\n", 21);
	// Add client in list
	t_cli *new = NULL;
	t_cli *temp = vars->clients;

	new = calloc(1, sizeof(t_cli));
	if (!new)
		ft_error(vars, 1);
	else {
		if (temp == NULL){
			vars->clients = new;
			temp = new;
			temp->next = NULL;
			temp->fd = fd;
			temp->id = vars->id;
			vars->id = vars->id + 1;
			return temp->id;
		}
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->fd = fd;
		new->id = vars->id;
		vars->id = vars->id + 1;
		new->next = NULL;
	}
	printf("New client add fd = %d id = %d\n", fd, vars->id);
	write(2, "ft_add_client end\n", 19);
	return new->id;
}

int		ft_accept(t_vars *vars){
	write(2, "ft_accept start\n", 17);
	// This function accept connections and add in queue
	// return 0 - Success
	// return 1 - Error
	struct sockaddr_in	addr;
	socklen_t len = sizeof(addr);
	int new_id = 0;

	int fd = accept(vars->sock_fd, (struct sockaddr *) &addr, &len);
	if (fd < 0)
		return 1;
	else {
		// vars->id = vars->id + 1;
		new_id = ft_add_client(vars, fd);
		sprintf(vars->buff, "server: client %d just arrived\n", new_id);
		ft_send_all(fd, vars);
	}
	FD_SET(fd, &vars->all_conn);
	write(2, "ft_accept end\n", 15);
	return 0;
}

int		ft_rm_client(t_vars *vars, int fd){
	write(2, "ft_rm_client start\n", 20);
	// remove client connection and return id
	t_cli *temp = vars->clients;
	int	ret = 0;

	while(temp){
		if (temp->next && fd == temp->next->fd){
			int ret = temp->next->id;
			t_cli *tmp = temp->next->next;
			ret = temp->next->id;
			free(temp->next);
			temp->next = tmp;
			return ret;
		}
		temp = temp->next;
	}
	write(2, "ft_rm_client end\n", 18);
	return ret;
}

int		ft_get_id(t_vars *vars, int fd){
	write(2, "ft_get_id start\n", 17);
	// Search and return id for fd
	t_cli	*temp = vars->clients;

	while(temp){
		if (fd == temp->fd)
			return temp->id;
		temp = temp->next;
	}
	write(2, "ft_get_id end\n", 15);
	return 0;
}

int		ft_read(t_vars *vars, int fd){
	write(2, "ft_read start\n", 15);
	// Read message from fd
	// return 0 - Success
	// return 1 - Error
	int		ret = 1000;
	sprintf(vars->buff, "client %d: ", ft_get_id(vars, fd));
	int		temp = 0;

	while(ret == 1000){
		ret = recv(fd, vars->buff + strlen(vars->buff),
					(strlen(vars->buff) + 1000 < sizeof(vars->buff)) ? 1000 : sizeof(vars->buff) - strlen(vars->buff), 0);
		if (ret > 0)
			temp++;
		if (strlen(vars->buff) == sizeof(vars->buff))
			break;
	}
	if (ret <= 0 && ret == 0){
		bzero(&vars->buff, sizeof(vars->buff));
		sprintf(vars->buff, "server: client %d just left\n",   ft_rm_client(vars, fd));
		ft_send_all(fd, vars);
		FD_CLR(fd, &vars->all_conn);
		close(fd);
		bzero(&vars->buff, sizeof(vars->buff));
	}
	write(2, "ft_read end\n", 13);
	return 0;
}

int		main(int argc, char **argv){
	write(2, "Main start\n", 12);
	t_vars	vars;
	int		n;

	if (argc != 2){
		write(2, "Wrong number of arguments\n", 27);
		return 1;
	}
	if (ft_start_prepare(&vars, argv)){
		write(2, "Fatal error\n", 13);
		return 1;
	}
	while(1){
		vars.rfd = vars.wfd = vars.efd = vars.all_conn;
		int max_d = max_desc(&vars);
		if ((n = select(max_d + 1, &vars.rfd, &vars.wfd, &vars.efd, NULL)) < 0)
			write(2, "Select error\n", strlen("Select error\n"));
		write(2, "select ok\n", 11);
		for (int fd = 0; fd <= max_d; ++fd){
			if (FD_ISSET(fd, &vars.rfd)){ // need read
				if (fd == vars.sock_fd){
					if (ft_accept(&vars)){
						ft_error(&vars, 1);
					}
					break ;
				}
				ft_read(&vars, fd);
				if (strlen(vars.buff))
					ft_send_all(fd, &vars);
			}
			if (FD_ISSET(fd, &vars.efd)){ // have error
				bzero(&vars.buff, sizeof(vars.buff));
				sprintf(vars.buff, "server: client %d just left\n",   ft_rm_client(&vars, fd));
				ft_send_all(fd, &vars);
				FD_CLR(fd, &vars.all_conn);
				close(fd);
				bzero(&vars.buff, sizeof(vars.buff));
			}
		}
	}
	return (0);
}