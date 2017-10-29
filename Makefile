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
SRCS += ./src/rescale.c
SRCS += ./src/center.c
SRCS += ./src/center_utils.c
SRCS += ./src/point.c
SRCS += ./src/segment.c
SRCS += ./src/list.c
SRCS += ./src/tab.c
SRCS += ./src/isometric.c
SRCS += ./src/rotation.c
SRCS += ./src/projection.c
SRCS += ./src/move.c
SRCS += ./src/utils.c
SRCS += ./src/free_ressources.c

SRCS += ./src/zoom.c

INC += ./inc/fdf.h

OBJ = $(SRCS:.c=.o)

all: libft mlx $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(LIB) $(MLXFLAGS) $(SRCS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)
	cd ./libft && $(MAKE) clean

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: libft
libft:
	cd ./libft && $(MAKE)

.PHONY: mlx
mlx:
	cd ./minilibx && $(MAKE)
