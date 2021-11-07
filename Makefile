# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 14:11:52 by alafranc          #+#    #+#              #
#    Updated: 2021/11/07 23:11:32 by alafranc         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			= player

FILES_GENERAL = main.c

GENERATE_BOARD = init_board.c\
				 print_board.c

INPUT_PARSING =	init_params.c\
				get_param.c

PLAY_GAME =		get_first_player.c\
				get_opponent_move.c\
				opponent_move.c\
				player_move.c\
				put_move_on_board.c\
				run_game.c

MINIMAX			= minimax.c\
				calculator_score.c

FILES			= 	$(addprefix input_parsing/, ${INPUT_PARSING})\
					$(addprefix generate_board/, $(GENERATE_BOARD))\
					$(addprefix minimax/, $(MINIMAX))\
					$(addprefix play_game/, $(PLAY_GAME))\
					main.c

INC_FILES		= rush_02.h
INC_PATH		= ./includes/
INC				= $(addprefix ${INC_PATH}, ${INC_FILES})

SRC_PATH		= srcs
SRC				= $(addprefix ${SRC_PATH}/, ${FILES})

BIN_PATH		= bin
BIN 			= $(SRC:%.c=$(BIN_PATH)/%.o)

NAME_LIBFT 		= libft.a
LIBFT_PATH 		= libft/
LIBFT			= $(addprefix ${LIBFT_PATH}, ${NAME_LIBFT})

CC				= clang
RM				= rm -rf
FLAGS			= #-Wall -Wextra  -Werror -g3 -fsanitize=address
FLAGS_PROD		= -o3

all: 			${NAME}


run:			fclean ${NAME}

init:
				@$(shell mkdir -p $(BIN_PATH))
				@make -C ${LIBFT_PATH}
				@cp ${LIBFT} .


$(BIN): $(BIN_PATH)/%.o: %.c ${INC}
				@mkdir -p $(@D)
				@$(CC) $(FLAGS) -I ${INC_PATH} -o $@ -c $<
				@printf "\e[?25l\e[JRUSH_02 : \e[92m$(notdir $<)\e[0m\r"

${NAME}: 		init ${BIN}
				@${CC} ${FLAGS} ${BIN} -o ${NAME} ${NAME_LIBFT} -I ${INC_PATH} -lncurses
				@printf '\033[?25l\033[JRUSH_02 CREATED \033[92m✔ \033[0m\033[?25h\n'

clean:
				@make -C ${LIBFT_PATH} clean
				@${RM} ${BIN_PATH}
				@printf '\033[?25l\033[JRUSH_02 DELETED \033[92m✔ \033[0m\033[?25h\n'

fclean:			
				@make -C ${LIBFT_PATH} fclean
				@${RM} ${NAME_LIBFT}
				@${RM} ${BIN_PATH}
				@${RM} ${NAME}
				@printf '\033[?25l\033[JRUSH_02 DELETED \033[92m✔ \033[0m\033[?25h\n'
				
re:				fclean all

.PHONY: all clean fclean re bonus init