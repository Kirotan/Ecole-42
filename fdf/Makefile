# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2024/01/23 16:23:09 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
LIBFT_DIR		=./src/libft
LIBFT_NAME		= libft.a
LIBMLX			=./MLX42
LIBX			= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADERS			= -I./include -I$(LIBMLX)/include/MLX42/ -I$(LIBFT_DIR)/include

SRC_FILES	=	./src/fdf.c \
				./src/extract_array.c

OBJ_FILES	= $(SRC_FILES:.c=.o)


all: $(NAME) $(LIBFT_DIR)/$(LIBFT_NAME) $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJ_FILES) $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $(OBJ_FILES) $(LIBX) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)

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
