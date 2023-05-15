# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samartin <samartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 13:44:34 by samartin          #+#    #+#              #
#    Updated: 2023/05/15 11:54:26 by samartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
BNNAME	:= checker
CC		:= gcc
LFTDIR  := ./libft/
LIBFT	:= libft.a
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
SRC		:=	src/push_swap.c \
			src/push_swap_action_push.c \
			src/push_swap_action_rev_rotate.c \
			src/push_swap_action_rotate.c \
			src/push_swap_action_swap.c \
			src/push_swap_checks.c \
			src/push_swap_exit.c \
			src/push_swap_indexing.c \
			src/push_swap_insertion_index_updates.c \
			src/push_swap_insertion_process.c \
			src/push_swap_list.c \
			src/push_swap_parse.c \
			src/push_swap_parse_utils.c \
			src/push_swap_short_cases_algs.c \
			src/push_swap_sorting_algs.c
BNSRC	:=	bonus_src/checker.c \
			bonus_src/push_swap_action_push.c \
			bonus_src/push_swap_action_rev_rotate.c \
			bonus_src/push_swap_action_rotate.c \
			bonus_src/push_swap_action_swap.c \
			bonus_src/push_swap_checks.c \
			bonus_src/push_swap_exit.c \
			bonus_src/push_swap_list.c \
			bonus_src/push_swap_parse.c \
			bonus_src/push_swap_parse_utils.c
OBJ		:= ${SRC:.c=.o}
BNOBJ	:= ${BNSRC:.c=.o}

all: ${NAME}

${LFTDIR}${LIBFT}:
	@make -C ${LFTDIR}

${NAME}: ${OBJ} ${LFTDIR}${LIBFT}
	@${CC} ${OBJ} ${LFTDIR}${LIBFT} -o ${NAME}

${BNNAME}: ${BNOBJ} ${LFTDIR}${LIBFT}
	@${CC} ${BNOBJ} ${LFTDIR}${LIBFT} -o ${BNNAME}

bonus: ${BNNAME}

clean:
	@${RM} ${OBJ} ${BNOBJ}
	@make -C ${LFTDIR} clean

fclean: clean
	@${RM} ${NAME}
	@${RM} ${BNNAME}
	@${RM} ${LFTDIR}${LIBFT}

re: fclean all

.PHONY:	all clean fclean re