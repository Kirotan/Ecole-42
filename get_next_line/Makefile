#ARGUMENTS

NAME		= get_next_line.a
CFLAGS		= -Wall -Wextra -Werror -c
CC          = gcc

#SOURCES

SRC_FILES	=   get_next_line.c \
				get_next_line_utils.c

OBJ_FILES	= ${SRC_FILES:.c=.o}

#REGLES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	ar rcs $@  ${OBJ_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
