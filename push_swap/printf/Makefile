# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2024/01/03 16:19:31 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= printf.a
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
				ft_write_args_p.c

OBJ_FILES	= ${SRC_FILES:.c=.o}


all: ${NAME}

${NAME}: ../libft.a ${OBJ_FILES}
	ar rcs $@ ${OBJ_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
