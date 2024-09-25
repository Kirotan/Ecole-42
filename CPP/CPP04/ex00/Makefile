NAME			= Polymorphisme
CXXFLAGS		= -Wall -Wextra -Werror -Wshadow -std=c++98
CXX				= c++

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
	@$(CXX) $(OBJ_FILES) $(CXXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
