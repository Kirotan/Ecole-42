#ARGUMENTS

NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror -c
CC			= gcc

#SOURCES

SRC_FILES	=	ft_strlen.c \
				ft_memcpy.c \
				ft_strdup.c \
				ft_itoa.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_memset.c

OBJ_FILES	= ${SRC_FILES:.c=.o}

#REGLES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	@ar rcs $@  ${OBJ_FILES}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ_FILES}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
