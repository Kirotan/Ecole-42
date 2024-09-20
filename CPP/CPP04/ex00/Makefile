NAME			= Polymorphisme
CFLAGS			= -Wall -Wextra -Werror -Wshadow -std=c++98
CC				= c++

SRC_FILES	= main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp


OBJ_FILES	= $(SRC_FILES:%.cpp=object/%.o)
OBJ_DIR = object


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
