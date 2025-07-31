/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:43:10 by student           #+#    #+#             */
/*   Updated: 2025/07/31 19:11:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
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
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
}	t_game;

void	parse_map(char *file, t_game *game);
void	init_game(t_game *game);
void	load_textures(t_game *game);
void	render_map(t_game *game);
int		handle_keypress(int key, t_game *game);
int		close_game(t_game *game);
void	error_exit(char *msg);
void	validate_path(t_game *game);
void	free_map(char **map, int height);

#endif