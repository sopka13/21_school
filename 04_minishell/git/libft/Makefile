NAME			= libft.a

SRC				= ft_atoi.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_isalpha.c\
					ft_isdigit.c\
					ft_itoa.c\
					ft_itoa_llu.c\
					ft_memset.c\
					ft_realloc.c\
					ft_split.c\
					ft_strchr.c\
					ft_strcmp.c\
					ft_strcpy.c\
					ft_strdup.c\
					ft_strjoin.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strncmp.c\
					ft_strputend.c\
					ft_strtrim.c\
					ft_substr.c\
					get_next_line.c

OBJ				=${SRC:.c=.o}

CC				= gcc

AR				= ar rc

FLAGS			= -Wall -Wextra -Werror

HEADER			= libft.h

.c.o:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJ) $(HEADER)
				$(AR) $(NAME) $(OBJ)
				ranlib libft.a

all:			$(NAME)

clean:
				rm -f $(OBJ)

fclean:			clean
				rm -f $(OBJ) $(NAME)

re:				fclean all
