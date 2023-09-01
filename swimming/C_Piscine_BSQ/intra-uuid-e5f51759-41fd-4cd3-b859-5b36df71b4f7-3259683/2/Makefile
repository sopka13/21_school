SRCF			= ${shell find srcs -type f -name "*.c"}

INCF			= includes

OBJF			= ${SRCF:.c=.o}

NAME			= bsq

CC				= gcc

RM				= rm -f

FLAGS			= -Wall -Wextra -Werror -I${INCF}

.c.o:			
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}


${NAME}:		${OBJF}
				${CC} -o ${NAME} ${OBJF}

all:			${NAME}


clean:
				${RM} ${OBJF}

fclean:	clean
				${RM} ${NAME}

re:				fclean all

.PHONY:	all clean fclean re
