NAME		= warlock

SRCS		= main.cpp \
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

OBJS		= ${SRCS:.cpp=.o}

CC			= clang++

FLAGS		= -Wall -Wextra -Werror

HEADER		= Warlock.hpp\
				ASpell.hpp\
				ATarget.hpp\
				BrickWall.hpp\
				Dummy.hpp\
				Fireball.hpp\
				Fwoosh.hpp\
				Polymorph.hpp\
				SpellBook.hpp\
				TargetGenerator.hpp

RM			= rm -rf

.PHONY:		all clean re fclean

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS} ${HEADER}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

re:			fclean all

clean:
			${RM} ${OBJS}

fclean:
			${RM} ${OBJS} ${NAME}