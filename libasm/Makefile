NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SRCS:.s=.o)

NASM = nasm
NASMFLAGS = -f elf64

AR = ar rcs

TEST = test_libasm
MAIN = main.c
MAIN_OBJ = main.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

$(TEST): $(NAME) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -L. -lasm -o $(TEST)

test: $(TEST)

clean:
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re test
