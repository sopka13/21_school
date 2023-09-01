# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 16:55:16 by eyohn             #+#    #+#              #
#    Updated: 2021/10/17 23:05:28 by eyohn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= webserv	#program name

SRCS			= ${shell find ./srcs -type f -name *.cpp}		#take all source files

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -g -fstack-protector -pthread -std=c++98

RM				= rm -rf

HEADER			= ${shell find ./includes -type f -name *.hpp}	#take all headers

.PHONY:			all clean fclean re

.cpp.o:
				${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:		${OBJS} ${HEADER}
				${CC} ${FLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:
				${RM} ${OBJS} ${NAME}

re:				fclean all
