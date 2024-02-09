# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2024/02/09 16:55:54 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
LIBFT_DIR		=./src/libft
LIBFT_NAME		= libft.a
HEADERS			= -I./include -I$(LIBFT_DIR)/include

SRC_FILES	=	./src/pipex.c \
				./src/ft_error.c \
				./src/ft_execve.c

OBJ_FILES	= $(SRC_FILES:.c=.o)


all: $(NAME) $(LIBFT_DIR)/$(LIBFT_NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJ_FILES) $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $(OBJ_FILES) $(LIBFT_DIR)/$(LIBFT_NAME) $(CFLAGS) -o $(NAME)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ_FILES)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
