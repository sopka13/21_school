NAME			= warlock

SRCS			= main.cpp\
					Warlock.cpp\
					ASpell.cpp\
					ATarget.cpp\
					Dummy.cpp\
					Fwoosh.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -std=c++98

HEADERS			= Warlock.hpp\
					ASpell.hpp\
					ATarget.hpp\
					Dummy.hpp\
					Fwoosh.hpp

RM				= rm -rf

.PHONY:			all re clean fclean

.cpp.o:
				${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:		${OBJS} ${HEADERS}
				${CC} ${FLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:
				${RM} ${OBJS} ${NAME}

re:				fclean all