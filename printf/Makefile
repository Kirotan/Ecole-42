# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2023/11/13 14:59:06 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
LIBFT_DIR		=./libft
LIBFT_NAME		= libft.a

SRC_FILES	=	ft_printf.c \
				ft_write_args_c.c \
				ft_write_args_d.c \
				ft_write_args_u.c \
				ft_write_args_percent.c \
				ft_write_args_x.c \
				ft_write_args_p.c \

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
