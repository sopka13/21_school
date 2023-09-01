# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eyohn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/04 19:22:08 by eyohn             #+#    #+#              #
#    Updated: 2020/08/05 09:48:32 by eyohn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c ft_func.c ft_is_sort.c

OBJS		= ${SRCS:.c=.o}

FLAGS		= -Wall -Wextra -Werror

NAME		= ft_is_sort

NORM		= norminette -R CheckForbiddenSourceHeader

CC			= cc
RM			= rm -f

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

norm:		${NORM}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
