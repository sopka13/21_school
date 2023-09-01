SRC			= ${wildcard srcs/*.c}

OBJ			= ${SRC:.c=.o}

INC			= includes

NAME		= rush-02

RM			= rm -f

CC			= gcc

CCFLAGS		= -Wall -Wextra -Werror -I${INC}

.c.o:		
			${CC} ${CCFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJ}
			${CC} -o ${NAME} ${OBJ}

clean:		
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			clean fclean all

.PHONY:		all clean fclean re
