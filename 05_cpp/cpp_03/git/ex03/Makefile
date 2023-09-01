NAME			= Now

SRCS			= main.cpp\
					ClapTrap.cpp\
					ScavTrap.cpp\
					FragTrap.cpp\
					DiamondTrap.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -Wshadow -Wno-shadow

RM				= rm -rf

HEADER			= ClapTrap.hpp\
					ScavTrap.hpp\
					FragTrap.hpp\
					DiamondTrap.hpp

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