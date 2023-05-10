# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samartin <samartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 13:44:34 by samartin          #+#    #+#              #
#    Updated: 2023/05/10 14:54:35 by samartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
BNNAME	:= checker
CC		:= gcc
LFTDIR  := libft
LIBFT	:= libft.a
CFLAGS	:= -Wall -Wextra -Werror -g3
RM		:= rm -rf
SRC		:=	./src/push_swap.c \
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
BNSRC	:=	./bonus_src/checker.c \
			./bonus_src/push_swap_action_push.c \
			./bonus_src/push_swap_action_rev_rotate.c \
			./bonus_src/push_swap_action_rotate.c \
			./bonus_src/push_swap_action_swap.c \
			./bonus_src/push_swap_checks.c \
			./bonus_src/push_swap_exit.c \
			./bonus_src/push_swap_list.c \
			./bonus_src/push_swap_parse.c \
			./bonus_src/push_swap_parse_utils.c
OBJ		:= ${SRC:.c=.o}
BNOBJ	:= ${BNSRC:.c=.o}

all: ${NAME}

${LIBFT}:
	cd ${LFTDIR} && make all
	cd ${LFTDIR} && mv ${LIBFT} ..

${NAME}: ${OBJ} ${LIBFT}
	${CC} $^ -o ${NAME}

${BNNAME}: ${BNOBJ} ${LIBFT}
	${CC} $^ -o ${BNNAME}

bonus: ${BNNAME}
	
clean:
	${RM} ${OBJ} ${BNOBJ}
	cd ${LFTDIR} &&	make clean

fclean: clean
	${RM} ${NAME}
	${RM} ${BNNAME}
	${RM} ${LIBFT}

re: fclean all

.PHONY:	all clean fclean re