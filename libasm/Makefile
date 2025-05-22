NAME = libasm.a

SRCS_S = ft_strlen.s ft_strcpy.s ft_strcmp.s

OBJS = $(SRCS_S:.s=.o)

MAIN = main.c
MAIN_OBJ = main.o
EXE = test_libasm

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.s
	@$(CC) $(CFLAGS) -c $< -o $@

test: all $(MAIN)
	@$(CC) $(CFLAGS) -c $(MAIN) -o $(MAIN_OBJ)
	@$(CC) $(MAIN_OBJ) -L. -lasm -o $(EXE)

clean:
	@rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	@rm -f $(NAME) $(EXE)

re: fclean all
