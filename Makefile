# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samartin <samartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 13:44:34 by samartin          #+#    #+#              #
#    Updated: 2023/05/03 16:10:12 by samartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC		:= gcc
LFTDIR  := libft
LIBFT	:= libft.a
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
SRC		:= ./src/push_swap.c \
			./src/push_swap_action_push.c \
			./src/push_swap_action_rev_rotate.c \
			./src/push_swap_action_rotate.c \
			./src/push_swap_action_swap.c \
			./src/push_swap_checks.c \
			./src/push_swap_exit.c \
			./src/push_swap_indexing.c \
			./src/push_swap_insertion_index_updates.c \
			./src/push_swap_insertion_process.c \
			./src/push_swap_list.c \
			./src/push_swap_parse.c \
			./src/push_swap_parse_utils.c \
			./src/push_swap_short_cases_algs.c \
			./src/push_swap_sorting_algs.c
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