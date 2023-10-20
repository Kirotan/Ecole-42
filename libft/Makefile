#ARGUMENTS

NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror -c
CC		= gcc

#SOURCES

SRC_FILES	= ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \

OBJ_FILES	= ft_isalpha.o \
		ft_isdigit.o \
		ft_isalnum.o \
		ft_isascii.o \
		ft_isprint.o \
		ft_strlen.o \
		ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memmove.o \
		ft_strlcpy.o \
#REGLES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	${AR} rcs ${OBJ_FILES} -o ${NAME}

${OBJ_FILES}: ${SRC_FILES}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean all

 fclean all

OBJ_FILES	= ft_isalpha.o \
		ft_isdigit.o \
		ft_isalnum.o \
		ft_isascii.o \
		ft_isprint.o \
		ft_strlen.o \
		ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memmove.o \
		ft_strlcpy.o \

.PHONY: all clean fclean re
