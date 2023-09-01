NAME			= philo_bonus

SRCS			= ft_atoi.c\
					ft_create_forks.c\
					ft_create_semaphore.c\
					ft_exit.c\
					ft_get_args.c\
					ft_if_die.c\
					ft_itoa.c\
					ft_number_philo.c\
					ft_philo.c\
					ft_print.c\
					ft_print_status.c\
					ft_strlen.c\
					ft_wait_forks.c\
					main.c

OBJS			= ${SRCS:.c=.o}

CC				= gcc -g

RM				= rm -rf

FLAGS			= -Wall -Wextra -Werror -pthread

HEADER			= ./philo_bonus.h

all:			${NAME}

${NAME}:		${OBJS} ${HEADER}
				${CC} ${FLAGS} ${HEADER} ${OBJS} -o ${NAME}

clean:
				${RM} ${OBJS}

fclean:
				${RM} ${OBJS} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re