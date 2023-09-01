NAME			= AttackWeapon

SRCS			= main.cpp\
					HumanA.cpp\
					HumanB.cpp\
					Weapon.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -g

RM				= rm -rf

HEADER			= HumanA.hpp\
					HumanB.hpp\
					Weapon.hpp

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