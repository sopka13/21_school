NAME		    = libftprintf.a

SRC			    = ft_printf.c \
					ft_format.c \
					ft_printf_1.c \
					ft_relative.c \
					ft_digit.c \
					ft_flag_space.c \
					ft_flag_mns.c \
					ft_flag_pls.c \
					ft_flag_res.c \
					ft_flag_dot.c \
					ft_flag_percent.c \
					ft_di.c \
					ft_di2.c \
					ft_u.c \
					ft_spaceuns.c \
					ft_s.c \
					ft_p.c \
					ft_x.c \
					ft_c.c \
					ft_percent.c \

OBJ				=${SRC:.c=.o}

CC				= gcc

AR				= ar rc

FLAGS			= -Wall -Wextra -Werror

HEADER			= ft_printf.h

.c.o:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJ) $(HEADER) libft.a
				$(AR) $(NAME) $(OBJ) ./libft/*.o
				ranlib libftprintf.a

libft.a:		
				(cd ./libft/.;$(MAKE))

all:			$(NAME)

clean:
				rm -f $(OBJ)
				(cd ./libft/.;$(MAKE) clean)
				(cd ..)

fclean:			clean
				rm -f $(OBJ) $(NAME)
				(cd ./libft/.;$(MAKE) fclean)
				(cd ..)

re:				fclean all
