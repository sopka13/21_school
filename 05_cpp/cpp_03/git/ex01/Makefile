NAME			= Serena

SRCS			= main.cpp\
					ClapTrap.cpp\
					ScavTrap.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -g

RM				= rm -rf

HEADER			= ClapTrap.hpp\
					ScavTrap.hpp

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