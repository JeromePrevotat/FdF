CC = gcc
MAKE = make
CFLAGS = -Wall -Werror -Wextra
LIB = -L./libft -lft -L./minilibx -lmlx
MLXFLAGS = -framework OpenGL -framework AppKit
NAME = fdf

SRCS += ./src/main.c
SRCS += ./src/parsing.c
SRCS += ./src/window.c
SRCS += ./src/draw.c
SRCS += ./src/k_event.c
SRCS += ./src/point.c
SRCS += ./src/list.c

INC += ./inc/fdf.h

OBJ = $(SRCS:.c=.o)

all: libft mlx $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) $(MLXFLAGS) $(SRCS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: libft
libft:
	cd ./libft && $(MAKE)

.PHONY: mlx
mlx:
	cd ./minilibx && $(MAKE)
