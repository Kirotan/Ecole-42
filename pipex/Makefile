# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2024/02/18 15:56:35 by gdoumer          ###   ########.fr        #
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

SRC_FILES_BONUS	=	./src/pipex_bonus.c \
					./src/ft_error.c \
					./src/ft_execve.c

OBJ_FILES	= $(SRC_FILES:.c=.o)
OBJ_FILES_BONUS	= $(SRC_FILES_BONUS:.c=.o)


all: $(NAME) $(LIBFT_DIR)/$(LIBFT_NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJ_FILES) $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $(OBJ_FILES) $(LIBFT_DIR)/$(LIBFT_NAME) $(CFLAGS) -o $(NAME)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

bonus: $(OBJ_FILES_BONUS) $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $(OBJ_FILES_BONUS) $(LIBFT_DIR)/$(LIBFT_NAME) $(CFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ_FILES) $(OBJ_FILES_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
