# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eyohn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 20:37:49 by eyohn             #+#    #+#              #
#    Updated: 2020/08/03 19:03:06 by eyohn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c ft_putchar.c ft_strcmp.c input.c

OBJS		= ${SRCS:.c=.o}

FLAGS		= -Wall -Wextra -Werror

NAME		= ft_cat

CC			= cc
RM			= rm -f

.c.o:		
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${FUNC}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
