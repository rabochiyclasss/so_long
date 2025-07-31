/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:45:25 by student           #+#    #+#             */
/*   Updated: 2025/07/31 19:14:51 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void validate_walls(t_game *game)
{
    int y;
    int x;
    
    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if ((y == 0 || y == game->map_height - 1 || x == 0 || x == game->map_width - 1) 
                && game->map[y][x] != '1')
            {
                error_exit("Map not surrounded by walls");
            }
            x++;
        }
        y++;
    }
}

void validate_content(t_game *game)
{
    int y;
    int x;
    int exit_count = 0;
    int player_count = 0;
    
    y = -1;
    while (++y < game->map_height)
    {
        x = -1;
        while (++x < game->map_width)
        {
            if (game->map[y][x] == 'E')
                exit_count++;
            else if (game->map[y][x] == 'P')
                player_count++;
            else if (game->map[y][x] == 'C')
                game->collectibles++;
            else if (game->map[y][x] != '0' && game->map[y][x] != '1')
                error_exit("Invalid character in map");
        }
    }
    
    if (exit_count != 1)
        error_exit("Map must have exactly one exit");
    if (player_count != 1)
        error_exit("Map must have exactly one player");
    if (game->collectibles < 1)
        error_exit("Map must have at least one collectible");
}

static void	copy_map(t_game *game, char ***map_copy)
{
	int	i;

	*map_copy = malloc(sizeof(char *) * game->map_height);
	if (!*map_copy)
		error_exit("Malloc failed");
	i = -1;
	while (++i < game->map_height)
	{
		(*map_copy)[i] = ft_strdup(game->map[i]);
		if (!(*map_copy)[i])
			error_exit("Malloc failed");
	}
}

void validate_path(t_game *game)
{
    char **map_copy;
    int i;
    int j;
    int found_player = 0;
    
    // Создаем копию карты
    map_copy = malloc(sizeof(char *) * game->map_height);
    if (!map_copy)
        error_exit("Malloc failed");
    
    i = -1;
    while (++i < game->map_height)
    {
        map_copy[i] = ft_strdup(game->map[i]);
        if (!map_copy[i])
        {
            // Освобождаем уже созданные строки при ошибке
            while (--i >= 0)
                free(map_copy[i]);
            free(map_copy);
            error_exit("Malloc failed");
        }
    }
    
    // Находим позицию игрока
    i = -1;
    while (++i < game->map_height)
    {
        j = -1;
        while (++j < game->map_width)
        {
            if (map_copy[i][j] == 'P')
            {
                found_player = 1;
                game->player_x = j;
                game->player_y = i;
                map_copy[i][j] = '0'; // Для flood fill
            }
        }
    }
    
    if (!found_player)
    {
        free_map(map_copy, game->map_height);
        error_exit("Player not found in map copy");
    }
    
    int initial_collectibles = game->collectibles;
    game->collectibles = 0; // Сброс счетчика для flood fill
    
    // Запускаем flood fill
    flood_fill(map_copy, game, game->player_y, game->player_x);
    
    // Проверяем достижимость
    if (game->collectibles != initial_collectibles)
    {
        free_map(map_copy, game->map_height);
        error_exit("Some collectibles are not reachable");
    }
    
    if (!check_exit_reachable(map_copy, game))
    {
        free_map(map_copy, game->map_height);
        error_exit("Exit is not reachable");
    }
    
    // Восстанавливаем оригинальное значение
    game->collectibles = initial_collectibles;
    free_map(map_copy, game->map_height);
}

void parse_map(char *file, t_game *game)
{
    int fd;
    char *line;
    int i;
    size_t len;
    
    // Первое открытие файла для подсчета строк
    fd = open(file, O_RDONLY);
    if (fd < 0)
        error_exit("Map file not found");
    
    game->map_height = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map_height++;
        free(line);
    }
    close(fd);
    
    if (game->map_height == 0)
        error_exit("Map is empty");
    
    // Выделение памяти под карту
    game->map = malloc(sizeof(char *) * game->map_height);
    if (!game->map)
        error_exit("Malloc failed");
    
    // Второе открытие файла для чтения строк
    fd = open(file, O_RDONLY);
    if (fd < 0)
        error_exit("Map file not found");
    
    i = 0;
    while ((line = get_next_line(fd)) != NULL && i < game->map_height)
    {
        // Удаление символа новой строки в конце
        len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        
        game->map[i] = line;
        
        // Проверка ширины
        if (i == 0)
            game->map_width = ft_strlen(game->map[i]);
        else if ((int)ft_strlen(game->map[i]) != game->map_width)
            error_exit("Map is not rectangular");
        
        i++;
    }
    close(fd);
    
    // Проверка что считали все строки
    if (i != game->map_height)
        error_exit("Map reading inconsistency");
    
    validate_walls(game);
    validate_content(game);
    validate_path(game);
}

