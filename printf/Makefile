# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2023/11/08 22:27:57 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
LIBFT_DIR		=./libft
LIBFT_NAME		= libft.a

SRC_FILES	=	ft_printf.c \
				ft_sort.c \
				main.c

OBJ_FILES	= ${SRC_FILES:.c=.o}


all: ${NAME}

${NAME}: makelibft ${OBJ_FILES}
	ar rcs $@ ${OBJ_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

makelibft:
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}/${LIBFT_NAME} .
	mv ${LIBFT_NAME} ${NAME}

clean:
	rm -f ${OBJ_FILES}
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f ${NAME}
	cd $(LIBFT_DIR) && make clean

re: fclean all

.PHONY: all clean fclean re
