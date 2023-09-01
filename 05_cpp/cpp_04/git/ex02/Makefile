NAME			= PURIFY

SRCS			= main.cpp\
					AssaultTerminator.cpp\
					Squad.cpp\
					TacticalMarine.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -rf

HEADER			= AWeapon.hpp\
					AssaultTerminator.hpp\
					Squad.hpp\
					TacticalMarine.hpp\
					ISpaceMarine.hpp\
					ISquad.hpp

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