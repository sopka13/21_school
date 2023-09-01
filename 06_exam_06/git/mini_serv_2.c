/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:04:55 by eyohn             #+#    #+#             */
/*   Updated: 2022/02/15 07:55:12 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

typedef struct		s_cli {
	int				fd;
	int				id;
	struct s_cli	*next;
}					t_cli;


typedef struct		s_vars {
	// args
	char			**argv;
	// select
	fd_set			all_conn;
	fd_set			rfd;
	fd_set			wfd;
	fd_set			efd;
	// socket
	uint16_t			port;
	struct sockaddr_in	servaddr;
	int					sock_fd;
	// clients
	int				id;
	t_cli			*clients;
	// buff
	char			buff[42 * 4096];
}				t_vars;

int		ft_prepare(t_vars *vars){
	// write(2, "ft_prepare start\n", strlen("ft_prepare startn\n"));
	// Prepare vars for functions
	FD_ZERO(&vars->all_conn);
	FD_ZERO(&vars->rfd);
	FD_ZERO(&vars->wfd);
	FD_ZERO(&vars->efd);
	vars->id = 0;
	vars->clients = NULL;
	bzero(&vars->buff, sizeof(vars->buff));
	vars->port = atoi(vars->argv[1]);
	bzero(&vars->servaddr, sizeof(vars->servaddr));
	vars->servaddr.sin_family = AF_INET;
	vars->servaddr.sin_addr.s_addr = htonl(2130706433);
	vars->servaddr.sin_port = htons(vars->port);
	if ((vars->sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("1\n");
		return 1;
	}
	if (bind(vars->sock_fd, (const struct sockaddr *)&vars->servaddr, sizeof(vars->servaddr)) < 0){
		printf("2\n");
		return 1;
	}
	if (listen(vars->sock_fd, 0)){
		printf("3\n");
		return 1;
	}

	FD_SET(vars->sock_fd, &vars->all_conn);

	// write(2, "ft_prepare end\n", strlen("ft_prepare end\n"));
	return 0;
}

int		ft_max_fd(t_vars *vars){
	// printf("ft_max_fd start\n");
	// Return max_fd
	t_cli*	temp = vars->clients;
	int		ret = vars->sock_fd;

	while(temp){
		if (temp->fd > ret)
			ret = temp->fd;
		temp = temp->next;
	}
	// printf("ft_max_fd end ret = %d\n", ret);
	return ret;
}

int		ft_get_id(t_vars *vars, int fd){
	t_cli *temp = vars->clients;
	int ret = 0;

	while (temp){
		if (temp->fd == fd){
			ret = temp->id;
			break;
		}
		temp = temp->next;
	}
	return ret;
}

int		ft_rm_client(t_vars *vars, int fd){
	t_cli *temp = vars->clients;
	t_cli *tmp = NULL;
	int ret = 0;

	if (temp && temp->fd == fd){
		vars->clients = temp->next;
		ret = temp->id;
		free(temp);
		return ret;
	}
	while(temp->next){
		if (temp->next->fd == fd){
			ret = temp->next->id;
			tmp = temp->next->next;
			free(temp->next);
			temp->next = tmp;
			break ;
		}
	}
	return ret;
}

int		ft_send_all(t_vars *vars, int fd){
	printf("ft_send_all start\n");
	// Send buffer for all clients
	t_cli *temp = vars->clients;

	while(temp){
		if (temp->fd != fd && FD_ISSET(temp->fd, &vars->wfd)){
			int i = send(temp->fd, &vars->buff, strlen(vars->buff), 0);
			if (i < 0)
				return 1;
		}
		temp = temp->next;
	}
	bzero(&vars->buff, sizeof(vars->buff));
	printf("ft_send_all end\n");
	return 0;
}

int		ft_read_data(t_vars *vars, int fd){
	printf("ft_read_data start\n");
	// Read data from fd and write in buffer
	int	ret = 1000;
	sprintf(vars->buff, "client %d: ", ft_get_id(vars, fd));
	int temp = 0;
	int id = 0;

	while(ret == 1000){
		ret = recv(fd, vars->buff + strlen(vars->buff),
				(strlen(vars->buff) + 1000 < sizeof(vars->buff)) ? 1000 : sizeof(vars->buff) - strlen(vars->buff), 0);
		if (ret > 0)
			temp++;
		if (ret <= 0 && temp == 0){
			id = ft_rm_client(vars, fd);
			FD_CLR(fd, &vars->all_conn);
			close(fd);
			sprintf(vars->buff, "server: client %d just left\n", id);
			ft_send_all(vars, fd);
			bzero(&vars->buff, sizeof(vars->buff));
		}
	}

	printf("ft_read_data end\n");
	return 0;
}

int		ft_add_client(t_vars *vars, int fd){
	// printf("ft_add_client start\n");
	// Add client in list
	t_cli *temp = vars->clients;
	t_cli *new;

	new = calloc(1, sizeof(t_cli));
	if (!new)
		return 1;
	else {
		if (temp == NULL){
			vars->clients = new;
			new->fd = fd;
			new->id = vars->id;
			vars->id = vars->id + 1;
			new->next = NULL;
			return new->id;
		}
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->fd = fd;
		new->id = vars->id;
		vars->id = vars->id + 1;
		new->next = NULL;
	}
	// printf("ft_add_client end\n");
	return new->id;
}

int		ft_accept(t_vars *vars){
	// Accept conection and read data
	int fd = 0;
	struct sockaddr str;
	socklen_t len = sizeof(str);
	int id = 0;

	// accept
	if ((fd = accept(vars->sock_fd, &str, &len)) < 0)
		return 1;
	else {
		id = ft_add_client(vars, fd);
		sprintf(vars->buff, "server: client %d just arrived\n", id);
		ft_send_all(vars, fd);
	}
	FD_SET(fd, &vars->all_conn);
	// read data
	// ft_read_data(vars, fd);
	// send all

	return 0;
}

int		ft_error(t_vars *vars){
	// Free memory and exit
	t_cli *temp = vars->clients;
	t_cli *tmp = NULL;

	while(temp){
		tmp = temp;
		temp = tmp->next;
		free(tmp);
	}

	write(2, "Fatal error\n", strlen("Fatal error\n"));
	exit(1);
}

int		main(int argc, char **argv){
	// write(2, "Main start\n", strlen ("Main start\n"));
	t_vars		vars;
	vars.argv = argv;
	int			n = 0;
	
	if(argc != 2){
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		return 1;
	}
	if(ft_prepare(&vars)){
		write(2, "Fatal error\n", strlen("Fatal error\n"));
		return 1;
	}
	while(1){
		vars.rfd = vars.wfd = vars.efd = vars.all_conn;
		int max_fd = ft_max_fd(&vars);
		if ((n = select(max_fd + 1, &vars.rfd, &vars.wfd, &vars.efd, NULL)) < 0)
			printf ("Select error\n");
		for (int fd = 0; fd <= max_fd; ++fd){
			if(FD_ISSET(fd, &vars.rfd)){
				if (fd == vars.sock_fd){
					if(ft_accept(&vars))
						ft_error(&vars);
					break;
				}
				ft_read_data(&vars, fd);
				ft_send_all(&vars, fd);
			}
			if(FD_ISSET(fd, &vars.efd)){
				int id = ft_rm_client(&vars, fd);
				FD_CLR(fd, &vars.all_conn);
				close(fd);
				sprintf(vars.buff, "server: client %d just left\n", id);
				ft_send_all(&vars, fd);
				bzero(&vars.buff, sizeof(vars.buff));
			}
		}
	}
	// write(2, "Main end\n", strlen ("Main end\n"));
	return 0;
}