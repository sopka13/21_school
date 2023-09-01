SRCF			= ${shell find srcs -type f -name "*.c"}

INCF			= includes

OBJF			= ${SRCF:.c=.o}

NAME			= bsq

CC				= gcc

FLAGS			= -Wall -Wextra -Werror -I${INCF}

.c.o:			
				${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM				= rm -f

all:			${NAME}

${NAME}:		${OBJF}
				${CC} -o ${NAME} ${OBJF}

clean:			${RM} ${OBJF}
