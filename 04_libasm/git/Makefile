NAME			= libasm.a

SRC				= ft_strlen.s\
					ft_strcpy.s\
					ft_strcmp.s\
					ft_write.s\
					ft_read.s\
					ft_strdup.s

OBJS			= $(SRC:.s=.o)

ASM				= nasm

ASMFLAGS		= -f elf32

.PHONY:			all clean fclean re test

.s.o:
				$(ASM) $(ASMFLAGS) $< -o $@

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

all:			$(NAME)

clean:
				rm -f $(OBJS)

fclean:
				rm -f $(OBJS) $(NAME) libasm

re:				fclean all

test:			$(NAME)
				gcc -no-pie main.c $(NAME) -o libasm -g
