NAME		= libft.a

SRC			= ft_atoi.c \
				ft_abs.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_itoahex.c \
				ft_itoahexunl.c \
				ft_itoauns.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
                ft_putchar.c \
                ft_putstr.c \
                ft_putstrn.c \
                ft_putnbr.c \
                ft_putnbruns.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strtoupper.c \
				ft_strmapi.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_strputend.c \
				ft_strputst.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \

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
