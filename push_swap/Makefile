# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2023/12/04 17:18:17 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftpush_swap.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
LIBFT_DIR		=./libft
LIBFT_NAME		= libft.a

SRC_FILES	=	push_swap.c \

OBJ_FILES	= ${SRC_FILES:.c=.o}


all: ${NAME}

${NAME}: ./libft/libft.a ${OBJ_FILES}
	ar rcs $@ ${OBJ_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

./libft/libft.a:
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}/${LIBFT_NAME} .
	mv ${LIBFT_NAME} ${NAME}

clean:
	rm -f ${OBJ_FILES}
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f ${NAME}
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
