NAME = so_long

SRC_DIR = srcs
SRC = main.c map_parser.c game_init.c graphics.c player_move.c utils.c
OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

GNL_DIR = $(SRC_DIR)/get_next_line
GNL_SRC = get_next_line.c get_next_line_utils.c
GNL_OBJ = $(addprefix $(GNL_DIR)/, $(GNL_SRC:.c=.o))

MLX_DIR = libs/mlx

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -I$(MLX_DIR)
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(MLX_DIR)
	rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re