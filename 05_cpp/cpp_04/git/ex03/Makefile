NAME			= BocalFantasy

SRCS			= main.cpp\
					AMateria.cpp\
					Character.cpp\
					Cure.cpp\
					Ice.cpp\
					MateriaSource.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -rf

HEADER			= AMateria.hpp\
					Character.hpp\
					Cure.hpp\
					Ice.hpp\
					ICharacter.hpp\
					IMateriaSource.hpp\
					MateriaSource.hpp

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