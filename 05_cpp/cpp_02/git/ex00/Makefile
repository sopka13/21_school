NAME			= a.out

SRCS			= main.cpp\
					Fixed.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror

RM				= rm -rf

HEADER			= Fixed.hpp

.PHONY:			all clean fclean re

.cpp.o:
				${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:		${OBJS}
				${CC} ${FLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:
				${RM} ${OBJS} ${NAME}

re:				fclean all