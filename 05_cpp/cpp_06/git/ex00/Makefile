NAME			= convert

SRCS			= Scalar.cpp\
					ft_bzero.cpp\
					ft_check_args.cpp\
					ft_exit_error.cpp\
					ft_init_vars.cpp\
					ft_write_result.cpp\
					main.cpp

OBJS			= ${SRCS:.cpp=.o}

CC				= clang++

FLAGS			= -Wall -Wextra -Werror -std=c++98

RM				= rm -rf

HEADER			= Scalar.hpp

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