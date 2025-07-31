/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:46:14 by student           #+#    #+#             */
/*   Updated: 2025/07/31 19:38:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Реализация flood fill
void flood_fill(char **map, t_game *game, int y, int x)
{
    if (y < 0 || y >= game->map_height || x < 0 || x >= game->map_width
        || map[y][x] == '1' || map[y][x] == 'X')
        return;
    
    if (map[y][x] == 'C')
        game->collectibles--;
    if (map[y][x] == 'E')
        map[y][x] = '1'; // Помечаем выход как стену
    
    map[y][x] = 'X';
    flood_fill(map, game, y - 1, x);
    flood_fill(map, game, y + 1, x);
    flood_fill(map, game, y, x - 1);
    flood_fill(map, game, y, x + 1);
}

// Проверка достижимости выхода
int check_exit_reachable(char **map, t_game *game)
{
    int y;
    int x;
    
    y = -1;
    while (++y < game->map_height)
    {
        x = -1;
        while (++x < game->map_width)
        {
            if (map[y][x] == 'E')
                return (0);
        }
    }
    return (1);
}

void free_map(char **map, int height)
{
    int i;
    
    if (!map)
        return;
    
    i = 0;
    while (i < height)
    {
        if (map[i])
            free(map[i]);
        i++;
    }
    free(map);
}

int close_game(t_game *game)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->map)
        free_map(game->map, game->map_height);
    exit(0);
    return (0);
}

void	ft_error(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}
