# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eyohn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 09:34:21 by eyohn             #+#    #+#              #
#    Updated: 2020/08/05 14:26:16 by eyohn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ${shell find srcs -type f -name "*.c"}

INCLUDES	= includes

OBJT		= ${SRCS:.c=.o}

FLAGS		= -Wall -Wextra -Werror -I ${INCLUDES}

NAME		= do-op

CC			= cc

RM			= rm -f

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJT}
			${CC} -o ${NAME} ${OBJT}

all:		${NAME}

clean:		${RM} ${OBJT}

fclean:		clean
			${RM} ${NAME}
