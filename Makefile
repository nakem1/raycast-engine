
NAME = cub3D

COMPILE = gcc -c -Wall -Werror -Wextra -O2
SRC_DIR = ./src

DIR_PARSE = $(SRC_DIR)/parse
DIR_GAME = $(SRC_DIR)/game_engine
DIR_INIT = $(SRC_DIR)/initCub3d
DIR_LIBFT = $(SRC_DIR)/libft
DIR_LIST = $(SRC_DIR)/lists
SRC = main.c \
	$(DIR_PARSE)/*.c \
	$(DIR_GAME)/*.c \
	$(DIR_INIT)/*.c \
	$(DIR_LIBFT)/*.c \
	$(DIR_LIST)/*.c

OBJ = *.o


MLX = ./minilibx/libmlx.a

#	-----MANDATORY PART BUILD-----

.PHONY: all
all: $(NAME)
	@echo CUB3D IS READY. SUCCESS PLS

$(NAME):
	$(COMPILE) $(SRC)
	gcc $(OBJ) -o cub3D $(MLX) -framework OpenGL -framework Appkit

.PHONY: clean
clean:
	@/bin/rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@/bin/rm -f cub3D

.PHONY: re
re: fclean all
