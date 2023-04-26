# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samartin <samartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 13:44:34 by samartin          #+#    #+#              #
#    Updated: 2023/04/25 13:57:54 by samartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC		:= gcc
LFTDIR  := libft
LIBFT	:= libft.a
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
SRC		:= ./src/push_swap.c ./src/push_swap_checks.c ./src/push_swap_commands.c ./src/push_swap_commands2.c ./src/push_swap_commands3.c ./src/push_swap_commands4.c ./src/push_swap_exit.c ./src/push_swap_indexing.c ./src/push_swap_list.c ./src/push_swap_parse.c ./src/push_swap_parse_utils.c ./src/push_swap_short_cases_algs.c
OBJ		:= ${SRC:.c=.o}

all: ${NAME}

${LIBFT}:
	cd ${LFTDIR} && make all
	cd ${LFTDIR} && mv ${LIBFT} ..

${NAME}: ${OBJ} ${LIBFT}
	${CC} $^ -o ${NAME}
	
clean:
	${RM} ${OBJ}
	cd ${LFTDIR} &&	make clean

fclean: clean
	${RM} ${NAME}
	${RM} ${LIBFT}

re: fclean all

.PHONY:	all clean fclean re