# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eyohn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 20:37:49 by eyohn             #+#    #+#              #
#    Updated: 2020/08/03 12:58:31 by eyohn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_display_file

CC			= cc
RM			= rm -f

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
