NAME			= War

SRCS			= main.cpp\
					AWeapon.cpp\
					Character.cpp\
					Enemy.cpp\
					PlasmaRifle.cpp\
					PowerFist.cpp\
					RadScorpion.cpp\
					SuperMutant.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -rf

HEADER			= AWeapon.hpp\
					Character.hpp\
					Enemy.hpp\
					PlasmaRifle.hpp\
					PowerFist.hpp\
					RadScorpion.hpp\
					SuperMutant.hpp

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