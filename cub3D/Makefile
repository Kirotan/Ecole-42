#########################################
## ARGUMENTS
#########################################
NAME	= cub3D

INCLUDES_PATH=	include
CC=				cc
CFLAGS=			-Wall -Wextra -Werror
CPPFLAGS=		-lglfw

LIBS_DIR=	./libft
MLX_PATH=	./mlx/build

all: $(NAME)

########################################
## SOURCES
########################################
SRC_FILES = main.c \
			power_on.c \
			init_gamer.c \
			movement.c \
			game_loop.c \
			display_background.c \
			display_gamer.c \
			draw_shape.c \
			display_map.c \
			normalize_angle.c \
			gamer_movement.c \
			ft_free_all.c \
			cast_rays.c \
			get_intersection.c \

SRC_FILES := $(addprefix src/, $(SRC_FILES))
OBJ_FILES = $(SRC_FILES:.c=.o)

########################################
## RULES
########################################

all: $(NAME)

DO_LIBS:
	@echo DOING LIBS
	@make -C $(LIBS_DIR) all

$(NAME): $(OBJ_FILES) | DO_LIBS
	@echo LINKING
	$(CC) $^ -L$(LIBS_DIR) -lft -L$(MLX_PATH) -lmlx42 -lm $(CFLAGS) $(CPPFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)
	@make -C $(LIBS_DIR) clean

fclean: clean
	@make -C $(LIBS_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re all
