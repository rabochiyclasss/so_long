NAME = so_long
SRC = main.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

MLX_PATH = ./minilib-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

# This ensures MiniLibX is compiled first
$(MLX_PATH)/libmlx_Linux.a:
	make -C $(MLX_PATH)

$(NAME): $(MLX_PATH)/libmlx_Linux.a $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re