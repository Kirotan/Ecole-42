NAME			=PhoneBook
CFLAGS			= -Wall -Wextra -Werror -std=c++98
CC				= c++

SRC_FILES	= main.cpp \
				PhoneBook.class.cpp \
				Contact.class.cpp \
				check_error.cpp \
				loop.cpp \
				which_command.cpp \

OBJ_FILES	= $(SRC_FILES:.cpp=.o)


all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(CFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
