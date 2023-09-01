NAME		= kernel

C_SRCS		= $(shell find ./srcs -type f -name "*.c")
ASM_SRCS	= $(shell find ./asm -type f -name "*.asm")

C_OBJS		= $(C_SRCS:.c=.o)
ASM_OBJS	= $(ASM_SRCS:.asm=.o)

GCC_FLAGS	= -fno-builtin \
				-fno-exceptions \
				-fno-stack-protector \
				-fno-rtti \
				-nostdlib \
				-nodefaultlibs \
				-m32

LD_FLAGS	= -m elf_i386 \
				-T link.ld

ASM_FLAGS	= -f elf32

CC			= gcc
ASM			= nasm
LD			= ld

RM			= rm -rf

.PHONY:		all clean fclean re

.c.o:
			$(CC) $(GCC_FLAGS) -c $< -o $(<:.c=.o)

%.o :		%.asm
			$(ASM) $(ASM_FLAGS) -o $@ $<

$(NAME):	$(ASM_OBJS) $(C_OBJS)
			$(LD) $(LD_FLAGS) -o $(NAME) $(ASM_OBJS) $(C_OBJS)

all:		$(NAME)

clean:
			$(RM) $(ASM_OBJS) $(C_OBJS)

fclean:
			$(RM) $(ASM_OBJS) $(C_OBJS) $(NAME)

re:			fclean all
