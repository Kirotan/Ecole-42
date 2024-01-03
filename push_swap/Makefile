# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2024/01/03 16:33:51 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
PRINTF_DIR		=./printf
PRINTF_NAME		= printf.a
LIBFT_DIR		=./libft
LIBFT_NAME		= libft.a

SRC_FILES	=	push_swap.c \
				check_error.c \
				generate_message_error.c

OBJ_FILES	= ${SRC_FILES:.c=.o}


all: ${NAME}

${NAME}: ${LIBFT_DIR}/${LIBFT_NAME} ${PRINTF_DIR}/${PRINTF_NAME} ${OBJ_FILES}
	ar rcs $@ ${OBJ_FILES}
	ar -x ${LIBFT_NAME}
	ar -x ${PRINTF_NAME}
	ar rcs $@ *.o

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

./libft/libft.a:
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}/${LIBFT_NAME} .

${PRINTF_DIR}/${PRINTF_NAME}:
	make -C ${PRINTF_DIR}
	cp ${PRINTF_DIR}/${PRINTF_NAME} .

clean:
	rm -f ${OBJ_FILES}
	rm -f *.o
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f ${NAME} ${LIBFT_NAME} ${PRINTF_NAME}
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
