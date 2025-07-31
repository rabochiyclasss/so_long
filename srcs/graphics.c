/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:46:54 by student           #+#    #+#             */
/*   Updated: 2025/07/31 18:46:58 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_textures(t_game *game)
{
	int	size;

	size = TILE_SIZE;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&size, &size);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&size, &size);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&size, &size);
	game->collect_img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectable.xpm", &size, &size);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&size, &size);
	if (!game->wall_img || !game->floor_img || !game->player_img
		|| !game->collect_img || !game->exit_img)
		error_exit("Failed to load textures");
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
				x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
					x * TILE_SIZE, y * TILE_SIZE);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}
