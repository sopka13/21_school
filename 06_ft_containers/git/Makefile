# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 11:57:26 by eyohn             #+#    #+#              #
#    Updated: 2022/01/18 21:36:21 by eyohn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_containers									#program name

SRCS			= main.cpp										#take all source files

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -g -fstack-protector -std=c++98

RM				= rm -rf

HEADER			= map.hpp\
					source.hpp\
					stack.hpp\
					vector.hpp			#take all headers

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