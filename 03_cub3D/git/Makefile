NAME		    = cub3D

SRC			    = ft_1.c \
					ft_2.c \
					ft_3.c \
					ft_4.c \
					ft_5.c \
					ft_6.c \
					ft_7.c \
					ft_8.c \
					ft_9.c \
					ft_10.c \
					ft_11.c \
					ft_12.c \
					ft_13.c \
					ft_14.c \
					ft_15.c \
					ft_16.c \
					ft_17.c \
					ft_18.c \
					ft_19.c \
					ft_20.c \
					ft_21.c \
					ft_22.c \
					ft_23.c \
					ft_24.c \
					ft_25.c \
					ft_26.c

OBJ				=${SRC:.c=.o}

CC				= gcc

AR				= ar rc

FLAGS			= -Wall -Wextra -Werror -g

HEADER			= cub3d.h

.c.o:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJ) $(HEADER)
				(cd ./minilibx-linux/.;$(MAKE))
				$(CC) $(OBJ) -L./minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) -g

all:			$(NAME)


clean:
				rm -f $(OBJ)
				(cd ./minilibx-linux/.;$(MAKE) clean)

fclean:			clean
				rm -f $(OBJ) $(NAME)

re:				fclean all