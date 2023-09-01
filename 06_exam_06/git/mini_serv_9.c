/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv_9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:49:40 by eyohn             #+#    #+#             */
/*   Updated: 2022/02/25 08:03:07 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

typedef struct			s_cli {
	int					fd;
	int					id;
	struct s_cli		*next;
}						t_cli;

typedef struct			s_vars {
	char				**argv;
	// socket
	fd_set				all_conn;
	fd_set				rfd;
	fd_set				wfd;
	fd_set				efd;
	int					sock_fd;
	// server
	struct sockaddr_in	servaddr;
	uint16_t			port;
	int					s_flag;
	// clients
	t_cli				*clients;
	int					id;
	int					id_from;
	// buffer
	char				buff[42 * 4096];
	char				temp[42 * 4096];
}						t_vars;

int		ft_prepare(t_vars *vars){
	FD_ZERO(&vars->all_conn);
	FD_ZERO(&vars->rfd);
	FD_ZERO(&vars->wfd);
	FD_ZERO(&vars->efd);
	vars->sock_fd = 0;
	bzero(&vars->servaddr, sizeof(vars->servaddr));
	bzero(&vars->buff, sizeof(vars->buff));
	bzero(&vars->temp, sizeof(vars->temp));
	vars->port = atoi(vars->argv[1]);
	vars->servaddr.sin_family = AF_INET;
	vars->servaddr.sin_addr.s_addr = htonl(2130706433);
	vars->servaddr.sin_port = htons(vars->port);
	if((vars->sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return 1;
	if(bind(vars->sock_fd, (const struct sockaddr *)&vars->servaddr, sizeof(vars->servaddr)) < 0)
		return 1;
	if(listen(vars->sock_fd, 0) < 0)
		return 1;
	FD_SET(vars->sock_fd, &vars->all_conn);
	vars->clients = NULL;
	vars->id = 0;
	vars->id_from = 0;
	vars->s_flag = 0;
	return 0;
}

void	ft_error(t_vars *vars){
	t_cli	*temp = vars->clients;
	t_cli	*tmp = NULL;

	while(temp){
		tmp = temp;
		temp = temp->next;
		free(tmp);
	}
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	exit(1);
}

int		ft_max_fd(t_vars *vars){
	t_cli	*temp = vars->clients;
	int max_fd = vars->sock_fd;

	while(temp){
		if(temp->fd > max_fd)
			max_fd = temp->fd;
		temp = temp->next;
	}
	return max_fd;
}

int		ft_add_client(t_vars *vars, int fd){
	t_cli	*temp = vars->clients;
	t_cli	*new = NULL;

	new = calloc(1, sizeof(t_cli));
	if(!new)
		ft_error(vars);
	if(!temp){
		vars->clients = new;
	} else {
		while(temp->next)
			temp = temp->next;
		temp->next = new;
	}
	new->fd = fd;
	new->id = vars->id;
	vars->id = vars->id + 1;
	new->next = NULL;
	return new->id;
}

void	ft_send_all(t_vars *vars, int fd){
	t_cli	*temp = vars->clients;

	while(temp){
		if(fd != temp->fd && FD_ISSET(temp->fd, &vars->wfd)){
			int i = 0;
			int j = 0;
			while(vars->buff[i]){
				vars->temp[j] = vars->buff[i];
				if(vars->temp[j] == '\n'){
					if(!vars->s_flag){
						char tmp[20];
						sprintf(tmp, "client %d: ", vars->id_from);
						send(temp->fd, tmp, strlen(tmp), 0);
					}
					send(temp->fd, vars->temp, strlen(vars->temp), 0);
					bzero(&vars->temp, sizeof(vars->temp));
					j = -1;
				}
				i++;
				j++;
			}
		}
		temp= temp->next;
	}
	return ;
}

int		ft_accept(t_vars *vars){
	struct sockaddr	str;
	socklen_t		len = sizeof(str);
	int		fd = 0;

	fd = accept(vars->sock_fd, (struct sockaddr *)&str, &len);
	if(fd < 0)
		return 1;
	int id = ft_add_client(vars, fd);
	sprintf(vars->buff, "server: client %d just arrived\n", id);
	vars->s_flag = 1;
	ft_send_all(vars, fd);
	vars->s_flag = 0;
	bzero(&vars->buff, sizeof(vars->buff));
	FD_SET(fd, &vars->all_conn);
	return 0;
}

int		ft_get_id(t_vars *vars, int fd){
	t_cli	*temp = vars->clients;

	while(temp){
		if(temp->fd == fd)
			return temp->id;
		temp = temp->next;
	}
	return 0;
}

int		ft_rm_client(t_vars *vars, int fd){
	t_cli	*temp = vars->clients;
	t_cli	*tmp = NULL;
	int id = 0;

	if(temp && temp->fd == fd){
		vars->clients = temp->next;
		id = temp->id;
		free(temp);
		return id;
	}
	while(temp->next){
		if(temp->next->fd == fd)
			break;
		temp = temp->next;
	}
	tmp = temp->next;
	temp->next = temp->next->next;
	id = tmp->id;
	free(tmp);
	return id;
}

void	ft_read_data(t_vars *vars, int fd){
	int ret = 1000;
	int temp = 0;
	vars->id_from = ft_get_id(vars, fd);

	while(ret == 1000){
		ret = recv(fd, vars->buff + strlen(vars->buff),
					(strlen(vars->buff) + 1000 < sizeof(vars->buff)) ? 1000 : sizeof(vars->buff) - strlen(vars->buff), 0);
		if(ret > 0)
			temp++;
		if(ret <= 0 && temp == 0){
			int id = ft_rm_client(vars, fd);
			sprintf(vars->buff, "server: client %d just left\n", id);
			vars->s_flag = 1;
			ft_send_all(vars, fd);
			vars->s_flag = 0;
			bzero(&vars->buff, sizeof(vars->buff));
			FD_CLR(fd, &vars->all_conn);
			close(fd);
		}
	}
	printf("Get message size = %lu\n", strlen(vars->buff));
	return ;
}

int		main(int argc, char **argv){
	t_vars	vars;
	int		max_fd = 0;
	vars.argv = argv;

	if(argc != 2){
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
		exit(1);
	}
	if(ft_prepare(&vars))
		ft_error(&vars);
	while(1){
		vars.rfd = vars.wfd = vars.efd = vars.all_conn;
		max_fd = ft_max_fd(&vars);
		if(select(max_fd + 1, &vars.rfd, &vars.wfd, &vars.efd, NULL) < 0)
			continue ;
		for(int fd = 0; fd <= max_fd; ++fd){
			if(FD_ISSET(fd, &vars.rfd)){
				if(fd == vars.sock_fd){
					if(ft_accept(&vars))
						ft_error(&vars);
					break ;
				}
				ft_read_data(&vars, fd);
				if(strlen(vars.buff)){
					ft_send_all(&vars, fd);
					bzero(&vars.buff, sizeof(vars.buff));
				}
			}
			if(FD_ISSET(fd, &vars.efd)){
				int id = ft_rm_client(&vars, fd);
				sprintf(vars.buff, "server: client %d just left\n", id);
				vars.s_flag = 1;
				ft_send_all(&vars, fd);
				vars.s_flag = 0;
				bzero(&vars.buff, sizeof(vars.buff));
				FD_CLR(fd, &vars.all_conn);
				close(fd);
			}
		}
	}
	return 0;
}
