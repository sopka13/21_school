NAME			= warlock

SRCS			= main.cpp\
					ASpell.cpp\
					ATarget.cpp\
					BrickWall.cpp\
					Dummy.cpp\
					Fireball.cpp\
					Fwoosh.cpp\
					Polymorph.cpp\
					SpellBook.cpp\
					TargetGenerator.cpp\
					Warlock.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -std=c++98

HEADERS			= Warlock.hpp\
					ASpell.hpp\
					ATarget.hpp\
					BrickWall.hpp\
					Dummy.hpp\
					Fireball.hpp\
					Fwoosh.hpp\
					Polymorph.hpp\
					SpellBook.hpp\
					TargetGenerator.hpp

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