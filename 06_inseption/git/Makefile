# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 17:47:02 by eyohn             #+#    #+#              #
#    Updated: 2022/02/05 22:31:20 by eyohn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= srcs

SPACE			= 'inception'

all:			# build containers and run it
				$(shell mkdir db-data wp-data ip)
				docker-compose -f srcs/docker-compose.yml build
				docker-compose -f srcs/docker-compose.yml up
				# docker-compose -f srcs/docker-compose.yml -p ${SPACE} up
				# (cd ${SRCS}; docker-compose -p ${SPACE} up --build -d)

stop:			# stop space_name
				(cd ${SRCS}; docker-compose down)
				# (cd ${SRCS}; docker-compose -p ${SPACE} down)

clear:			# clear all data
				docker rm $(shell docker ps -a -q)
				docker rmi -f $(shell docker images -qa)
				docker volume rm $(shell docker volume ls -q)
				docker system prune -a --force
				$(shell rm -rf db-data/*)
				$(shell rm -rf wp-data/*)
				$(shell rm -rf ip/*)

re:				stop all