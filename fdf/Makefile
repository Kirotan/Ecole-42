# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2024/01/18 18:51:27 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
LIBFT_DIR		=./src/libft
LIBFT_NAME		= libft.a
LIBMLX			=./MLX42
LIBX			= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADERS	:= -I ./include -I $(LIBMLX)/include/MLX42/

SRC_FILES	=	fdf.c \

OBJ_FILES	= $(SRC_FILES:.c=.o)


all: $(NAME) libmlx $(LIBFT_DIR)/$(LIBFT_NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(LIBX) $(HEADERS) -o $(NAME)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ_FILES)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libmlx
