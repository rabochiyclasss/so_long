/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:49:23 by student           #+#    #+#             */
/*   Updated: 2025/07/31 19:35:27 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    
    if (argc != 2)
        ft_error("Usage: ./so_long map.ber");
    
    ft_memset(&game, 0, sizeof(t_game));
    parse_map(argv[1], &game);
    
    game.mlx = mlx_init();
    if (!game.mlx)
        ft_error("MLX initialization failed");
    
    game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE,
                             game.map_height * TILE_SIZE, "so_long");
    if (!game.win)
        ft_error("Window creation failed");
    
    init_game(&game);
    load_textures(&game);
    render_map(&game);
    
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop(game.mlx);
    return (0);
}

