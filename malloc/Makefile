# Detect HOSTTYPE
ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

# Nom des fichiers
NAME      = libft_malloc_$(HOSTTYPE).so
SYMLINK   = libft_malloc.so
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

TEST_NAME = test_malloc
TEST_SRC  = main.c

# Compilation
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -fPIC
LDFLAGS = -shared

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Commandes
RM    = rm -f
MKDIR = mkdir -p

# Règles
all: $(LIBFT) $(NAME) symlink

$(LIBFT):
	@echo ">> Compilation de libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBFT)

symlink:
	@ln -sf $(NAME) $(SYMLINK)
	@echo ">> Lien symbolique créé : $(SYMLINK) -> $(NAME)"

test: $(NAME)
	@echo "=> Construction de l'exécutable de test ($(TEST_NAME))"
	gcc $(CFLAGS) -I src \
		$(TEST_SRC) \
		-L. -Wl,-rpath=. -lft_malloc \
		-o $(TEST_NAME)
	@echo "=> Pour exécuter : ./${TEST_NAME}"

clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(SYMLINK) $(TEST_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re symlink test
