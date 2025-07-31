#ifndef SO_LONG_H
# define SO_LONG_H

# include "../includes/get_next_line.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <../libs/mlx/mlx.h>
# include <stdlib.h>

# define TILE_SIZE 64

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     moves;
    void    *wall_img;
    void    *floor_img;
    void    *player_img;
    void    *collect_img;
    void    *exit_img;
}   t_game;

// Прототипы функций
void    parse_map(char *file, t_game *game);
void    init_game(t_game *game);
void    load_textures(t_game *game);
void    render_map(t_game *game);
int     handle_keypress(int key, t_game *game);
int     close_game(t_game *game);
void    ft_error(char *msg);
void    validate_path(t_game *game);
void    free_map(char **map, int height);
void    flood_fill(char **map, t_game *game, int y, int x);
int     check_exit_reachable(char **map, t_game *game);

#endif