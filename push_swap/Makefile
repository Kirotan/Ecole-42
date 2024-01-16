# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 12:08:12 by gdoumer           #+#    #+#              #
#    Updated: 2024/01/16 16:20:07 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address
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
				delete_node.c \
				algorithm.c \
				sort_two.c \
				sort_three.c \
				sort_five.c \
				sort_radix.c \
				free_dlist.c

OBJ_FILES	= $(SRC_FILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJ_FILES) | $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $^ -L$(LIBFT_DIR) -lft $(CFLAGS) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

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
