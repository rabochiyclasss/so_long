NAME = so_long

SRC_DIR = srcs
SRC = main.c map_parser.c game_init.c graphics.c player_move.c utils.c
OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

GNL_DIR = $(SRC_DIR)/get_next_line
GNL_SRC = get_next_line.c get_next_line_utils.c
GNL_OBJ = $(addprefix $(GNL_DIR)/, $(GNL_SRC:.c=.o))

LIBFT_DIR = libs/libft
MLX_DIR = libs/mlx

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(SRC_DIR)/get_next_line
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re