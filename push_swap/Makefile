# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2024/01/06 15:32:54 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
LIBFT_DIR		=./libft
LIBFT_NAME		= libft.a

SRC_FILES	=	push_swap.c \
				check_error.c \
				generate_message_error.c \
				initialize_double_list.c \
				new_double_list.c \
				front_add_double_list.c \
				back_add_double_list.c \
				length_double_list.c \
				create_index.c \
				ft_push.c \
				ft_swap.c \
				ft_rotate.c \
				ft_reverse.c \
				test_print.c

OBJ_FILES	= ${SRC_FILES:.c=.o}


all: ${NAME}

${NAME}: ${LIBFT_DIR}/${LIBFT_NAME} ${OBJ_FILES}
	ar rcs $@ ${OBJ_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${LIBFT_DIR}/${LIBFT_NAME}:
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}/${LIBFT_NAME} .
	mv ${LIBFT_NAME} ${NAME}

clean:
	rm -f ${OBJ_FILES}
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f ${NAME} ${LIBFT_NAME} ${PRINTF_NAME}
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
