# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samartin <samartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 13:44:34 by samartin          #+#    #+#              #
#    Updated: 2023/03/21 14:20:56 by samartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC		:= gcc
LFTDIR  := libft
LIBFT	:= libft.a
VPATH	:= libft
CFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
SRC		:= push_swap.c
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