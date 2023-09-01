/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 07:55:30 by eyohn             #+#    #+#             */
/*   Updated: 2022/02/15 09:27:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

typedef struct		s_cli {
	int				fd;
	int				id;
	struct s_cli	*next;
}					t_cli;

typedef struct		s_vars {
	char			**argv;
	// socket
	fd_set			all_conn;
	fd_set			rfd;
	fd_set			wfd;
	fd_set			efd;
	// socket
	int					sock_fd;
	struct sockaddr_in	servaddr;
	uint16_t			port;
	// buff
	char			buff[42 * 4096];
	// clients
	t_cli			*clients;
	int				id;
}					t_vars;

void	ft_error(t_vars *vars){
	t_cli *temp = vars->clients;
	t_cli *tmp = NULL;

	while(temp){
		tmp = temp;
		temp = temp->next;
		free(tmp);
	}
	exit(1);
}

int		ft_prepare(t_vars *vars){
	FD_ZERO(&vars->all_conn);
	FD_ZERO(&vars->rfd);
	FD_ZERO(&vars->wfd);
	FD_ZERO(&vars->efd);
	bzero(&vars->buff, sizeof(vars->buff));
	bzero(&vars->servaddr, sizeof(vars->servaddr));
	vars->port = atoi(vars->argv[1]);
	vars->servaddr.sin_family = AF_INET;
	vars->servaddr.sin_addr.s_addr = htonl(2130706433);
	vars->servaddr.sin_port = htons(vars->port);
	if ((vars->sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ft_error(vars);
	if (bind(vars->sock_fd, (const struct sockaddr *)&vars->servaddr, sizeof(vars->servaddr)) < 0)
		ft_error(vars);
	if (listen(vars->sock_fd, 0))
		ft_error(vars);
	FD_SET(vars->sock_fd, &vars->all_conn);
	vars->clients = NULL;
	vars->id = 0;
	return 0;
}

int		ft_max_fd(t_vars *vars){
	t_cli *temp = vars->clients;
	int ret = vars->sock_fd;

	while(temp){
		if(temp->fd > ret)
			ret = temp->fd;
		temp = temp->next;
	}
	// printf("ft_max_fd end ret = %d\n", ret);
	return ret;
}

int		ft_add_client(t_vars *vars, int fd){
	t_cli *temp = vars->clients;
	t_cli *new = NULL;
	
	new = calloc(1, sizeof(t_cli));
	if(!new)
		ft_error(vars);
	if(temp == NULL){
		vars->clients = new;
		new->fd = fd;
		new->id = vars->id;
		vars->id = vars->id + 1;
		new->next = NULL;
		return new->id;
	}
	while(temp->next)
		temp = temp->next;
	temp->next = new;
	new->fd = fd;
	new->id = vars->id;
	vars->id = vars->id + 1;
	new->next = NULL;
	return new->id;
}

void	ft_send_all(t_vars *vars, int fd){
	printf("ft_send_all start\n");
	t_cli *temp = vars->clients;

	while(temp){
		if(fd != temp->fd && FD_ISSET(temp->fd, &vars->wfd))
			send(temp->fd, vars->buff, strlen(vars->buff), 0);
		temp = temp->next;
	}
	printf("ft_send_all end\n");
	return ;
}

int		ft_accept(t_vars *vars){
	printf("ft_accept start\n");
	struct sockaddr str;
	socklen_t len = sizeof(str);
	int fd = 0;
	int id = 0;

	fd = accept(vars->sock_fd, (struct sockaddr *)&str, &len);
	if (fd < 0)
		return 1;
	else {
		id = ft_add_client(vars, fd);
		sprintf(vars->buff, "server: client %d just arrived\n", id);
		ft_send_all(vars, fd);
		bzero(&vars->buff, sizeof(vars->buff));
		FD_SET(fd, &vars->all_conn);
	}
	printf("ft_accept end\n");
	return 0;
}

int		ft_get_id(t_vars *vars, int fd){
	t_cli *temp = vars->clients;

	while(temp){
		if (temp->fd == fd)
			return temp->id;
		temp = temp->next;
	}
	return 0;
}

int		ft_rm_client(t_vars *vars, int fd){
	t_cli *temp = vars->clients;
	t_cli *tmp = NULL;
	int ret = 0;

	if (temp && temp->fd == fd){
		tmp = temp->next;
		ret = temp->id;
		free(temp);
		vars->clients = tmp;
		return ret;
	}
	while (temp->next && temp->next->fd != fd)
		temp = temp->next;
	ret = temp->next->id;
	tmp = temp->next->next;
	free(temp->next);
	temp->next = tmp;
	return ret;
}

int		ft_read_data(t_vars *vars, int fd){
	printf("ft_read_data start\n");
	int ret = 1000;
	int temp = 0;
	sprintf(vars->buff, "client %d: ", ft_get_id(vars, fd));

	while (ret == 1000){
		ret = recv(fd, vars->buff + strlen(vars->buff),
					(strlen(vars->buff) + 1000 < sizeof(vars->buff)) ? 1000 : sizeof(vars->buff) - strlen(vars->buff), 0);
		// printf("strlen = %lu ret = %d\n", strlen(vars->buff), ret);
		if (ret > 0)
			temp++;
		if (ret <= 0 && temp == 0){
			int id = ft_rm_client(vars, fd);
			bzero(&vars->buff, sizeof(vars->buff));
			sprintf(vars->buff, "server: client %d just left\n", id);
			ft_send_all(vars, fd);
			bzero(&vars->buff, sizeof(vars->buff));
			FD_CLR(fd, &vars->all_conn);
			close(fd);
			break ;
		}
	}
	printf("ft_read_data end\n");
	return 0;
}

int		main(int argc, char **argv){
	t_vars vars;
	vars.argv = argv;
	int max_fd = 0;

	if(argc != 2)
		ft_error(&vars);
	if(ft_prepare(&vars))
		ft_error(&vars);
	while(1){
		vars.rfd = vars.wfd = vars.efd = vars.all_conn;
		max_fd = ft_max_fd(&vars);
		if(select(max_fd + 1, &vars.rfd, &vars.wfd, &vars.efd, NULL) <= 0)
			continue ;
		// printf("fine\n");
		for(int fd = 0; fd <= max_fd; ++fd){
			if(FD_ISSET(fd, &vars.rfd)){
				// printf("fine");
				if(fd == vars.sock_fd){
					if(ft_accept(&vars))
						ft_error(&vars);
					continue ;
				}
				ft_read_data(&vars, fd);
				if(strlen(vars.buff))
					ft_send_all(&vars, fd);
			}
			if(FD_ISSET(fd, &vars.efd)){
				int id = ft_rm_client(&vars, fd);
				sprintf(vars.buff, "server: client %d just left\n", id);
				ft_send_all(&vars, fd);
				bzero(&vars.buff, sizeof(vars.buff));
				FD_CLR(fd, &vars.all_conn);
				close(fd);
			}
		}
	}
	return 0;
}