NAME		= libft.a

SRC			= $(shell find . -type f -name "*.c")

OBJ				=${SRC:.c=.o}

CC				= gcc

AR				= ar rc

FLAGS			= -Wall -Wextra -Werror -g

HEADER			= libft.h

.c.o:			
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJ) $(HEADER)
				$(AR) $(NAME) $(OBJ)

all:			$(NAME)

clean:
				-rm -f $(OBJ)

fclean:			clean
				-rm -f $(OBJ) $(NAME)

re:				fclean all
