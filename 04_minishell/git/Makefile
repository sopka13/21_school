NAME		= minishell
SHELL		=/bin/bash
define art
${GREEN}
                    M I N I S H E L L${RED}
,---,---,---,---,---,---,---,---,---,---,---,---,---,-------,
|1/2| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | + | ' | <-    |
|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|
| ->| | Q | W | E | R | T | Y | U | I | O | P | ] | ^ |     |
|-----',--',--',--',--',--',--',--',--',--',--',--',--'|    |
| Caps | A | S | D | F | G | H | J | K | L | \ | [ | * |    |
|----,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'---'----|
|    | < | Z | X | C | V | B | N | M | , | . | - |          |
|----'-,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|
| ctrl |  | alt |                          |  alt |  | ctrl |
'------'  '-----'--------------------------'------'  '------'

${BLUE}               eyohn & ssandman's minishell
${GREEN}                    build successful!${RESET}

endef
export art

define clean
${LIGHTPURPLE}
         ,,
       `7MM
         MM
 ,p6"bo  MM  .gP"Ya   ,6"Yb. `7MMpMMMb.
6M'  OO  MM ,M'   Yb 8)   MM   MM    MM
8M       MM 8M""""""  ,pm9MM   MM    MM
YM.    , MM YM.    , 8M   MM   MM    MM
 YMbmd'.JMML.`Mbmmd' `Moo9^Yo.JMML  JMML.

${RED} all objs has been deleted!
                                         ${RESET}
endef
export clean

define fclean
${BLUE}

    ,...      ,,
  .d' ""    `7MM
  dM`         MM
 mMMmm,p6"bo  MM  .gP"Ya   ,6"Yb. `7MMpMMMb.
  MM 6M'  OO  MM ,M'   Yb 8)   MM   MM    MM
  MM 8M       MM 8M""""""  ,pm9MM   MM    MM
  MM YM.    , MM YM.    , 8M   MM   MM    MM
.JMML.YMbmd'.JMML.`Mbmmd' `Moo9^Yo.JMML  JMML.

${RED} all objs, executable
 and lib file has been deleted!

                                         ${RESET}
endef
export fclean

ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

ifndef NOPRINT
MAKEFLAGS += --no-print-directory
endif

SRCS		= srcs/ft_atoi_exit_status.c\
				srcs/ft_atoi_spec.c\
				srcs/ft_cd.c\
				srcs/ft_change_env.c\
				srcs/ft_check_strt.c\
				srcs/ft_child_1.c\
				srcs/ft_clean_vars.c\
				srcs/ft_echo_arg_1.c\
				srcs/ft_echo_arg_2.c\
				srcs/ft_echo_arg_3.c\
				srcs/ft_echo_arg_4.c\
				srcs/ft_echo_arg_5.c\
				srcs/ft_echo_arg.c\
				srcs/ft_echo_arg_exep.c\
				srcs/ft_echo_arg_start.c\
				srcs/ft_echo.c\
				srcs/ft_env.c\
				srcs/ft_envp.c\
				srcs/ft_event.c\
				srcs/ft_exit_2.c\
				srcs/ft_exit.c\
				srcs/ft_export.c\
				srcs/ft_export_in.c\
				srcs/ft_export_s.c\
				srcs/ft_file_dc_s.c\
				srcs/ft_file_desc.c\
				srcs/ft_free_com_l.c\
				srcs/ft_free_s.c\
				srcs/ft_free_ss.c\
				srcs/ft_get_3.c\
				srcs/ft_get_com_if_1.c\
				srcs/ft_get_com_if_2.c\
				srcs/ft_get_com_if_4.c\
				srcs/ft_get_com_if_5.c\
				srcs/ft_get_command.c\
				srcs/ft_get_com_syntax_err_1.c\
				srcs/ft_get_com_syntax_err_2.c\
				srcs/ft_get_envp.c\
				srcs/ft_get_result.c\
				srcs/ft_get_tilda.c\
				srcs/ft_get_var_value.c\
				srcs/ft_history.c\
				srcs/ft_if_have_equal.c\
				srcs/ft_if_have_tilda.c\
				srcs/ft_init_fd.c\
				srcs/ft_init_flags.c\
				srcs/ft_keys.c\
				srcs/ft_leigth_num.c\
				srcs/ft_new_line_error.c\
				srcs/ft_non_file.c\
				srcs/ft_not_equal.c\
				srcs/ft_num.c\
				srcs/ft_num_if_1.c\
				srcs/ft_only_space.c\
				srcs/ft_open_desc_1.c\
				srcs/ft_open_desc_2.c\
				srcs/ft_open_desc_3.c\
				srcs/ft_open_desc.c\
				srcs/ft_open_desc_synerr.c\
				srcs/ft_parce.c\
				srcs/ft_parent_2.c\
				srcs/ft_print.c\
				srcs/ft_pt_1.c\
				srcs/ft_putendstr_arr.c\
				srcs/ft_pwd.c\
				srcs/ft_read_input.c\
				srcs/ft_realloc_arr.c\
				srcs/ft_rem_elem_arr.c\
				srcs/ft_rem_quotes_1.c\
				srcs/ft_rem_quotes_2.c\
				srcs/ft_rem_quotes_3.c\
				srcs/ft_rem_quotes_4.c\
				srcs/ft_rem_quotes.c\
				srcs/ft_repare_fd.c\
				srcs/ft_ret_null.c\
				srcs/ft_size_arr.c\
				srcs/ft_start_fork.c\
				srcs/ft_start_fork_exit_1.c\
				srcs/ft_start_fork_exit_2.c\
				srcs/ft_start_get_com.c\
				srcs/ft_start_input.c\
				srcs/ft_stop.c\
				srcs/ft_termcaps.c\
				srcs/ft_termprep.c\
				srcs/ft_unset.c\
				srcs/ft_valid_env_chr.c\
				srcs/ft_valid_name_export_1.c\
				srcs/ft_valid_name_export.c\
				srcs/ft_write_and_ret.c\
				srcs/main.c

OBJS		= ${SRCS:.c=.o}

CC			= @gcc
RM			= rm -f


LIBFT_FLAGS	= -Llibft -lft -lcurses

CFLAGS		= -Wall -Wextra -Werror -g

INCLUDES	= -I libft

HEADER		= ./minishell.h

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): ${HEADER} ${OBJS} | libft
		${CC} ${OBJS} ${LIBFT_FLAGS} -o ${NAME}
		@clear
		@echo "$$art"

all:	${NAME}

libft:
		@make --no-print-directory -C libft

clean:
		@make -C libft clean
		${RM} ${OBJS}
		@clear
		@echo "$$clean"

fclean:	clean
		@rm -f libft/libft.a
		${RM} ${NAME}
		clear
		@echo "$$fclean"

re:		fclean
		make all

.PHONY : all art clean fclean re libft
