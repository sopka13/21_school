NAME		= warlock

SRCS		= main.cpp \
				Warlock.cpp\
				ASpell.cpp\
				ATarget.cpp\
				Dummy.cpp\
				Fwoosh.cpp

OBJS		= ${SRCS:.cpp=.o}

CC			= clang++

FLAGS		= -Wall -Wextra -Werror

HEADER		= Warlock.hpp\
				ASpell.hpp\
				ATarget.hpp\
				Dummy.hpp\
				Fwoosh.hpp

RM			= rm -rf

.PHONY:		all clean re fclean

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS} ${HEADER}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}
all:
			${NAME}
re:	
			${RM} ${OBJS} ${NAME}
			all
clean:
			${RM} ${OBJS}
fclean:
			${RM} ${OBJS} ${NAME}