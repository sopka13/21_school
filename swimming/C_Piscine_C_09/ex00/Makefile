# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eyohn <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 20:37:49 by eyohn             #+#    #+#              #
#    Updated: 2020/08/02 20:46:29 by eyohn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_putchar.c ft_strlen.c ft_putstr.c ft_swap.c ft_strcmp.c

OBJS		= ${SRCS:.c=.o}

NAME		= libft

CC			= cc

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all			${NAME}

clean:		rm ${OBJS}
