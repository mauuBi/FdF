NAME = fdf

CC = cc

INCLUDES_PATH = includes

# MLX LIB
MLX_PATH = minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a

# LIBFT LIB
LIBFT_PATH = libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

MLX_FLAGS = -lX11 -lXext -lm -O3
CFLAGS = -I$(LIBFT_PATH) -I$(MLX_PATH) -I$(INCLUDES_PATH) -Wall -Wextra -Werror -g

SRC_FILES = src/main.c src/parsing/parser.c src/parsing/free.c src/parsing/utils.c \
			src/parsing/map.c src/parsing/color.c src/parsing/atoi.c src/render/free.c \
			src/render/draw.c src/render/point_utils.c src/render/event.c src/render/fdf_utils.c \
			src/render/coords.c src/render/init.c src/render/colors.c src/render/render.c \
			src/render/projection.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: libs $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

libs:
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ_FILES) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ_FILES)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re