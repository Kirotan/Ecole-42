# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 17:14:04 by gdoumer           #+#    #+#              #
#    Updated: 2024/03/04 11:05:10 by gdoumer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= philo
CFLAGS			= -Wall -Wextra -Werror -g3
CC				= gcc
HEADERS			= -I./include

SRC_FILES	=	./src/philo.c \
				./src/check_error.c \
				./src/utils.c \
				./src/get_data.c \
				./src/mechanism.c \
				./src/ft_gotto.c \
				./src/ft_gotto_odd.c \
				./src/ft_fork.c \
				./src/freeing_machine.c \
				./src/ft_thanatos.c \
				./src/hammer.c

OBJ_FILES	= $(SRC_FILES:.c=.o)


all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(CFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
