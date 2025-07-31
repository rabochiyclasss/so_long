/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:49:08 by student           #+#    #+#             */
/*   Updated: 2025/07/31 18:49:09 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return ;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
	{
		ft_printf("You win! Total moves: %d\n", game->moves);
		close_game(game);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = 'P';
	render_map(game);
}

int	handle_keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_game(game);
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, game->player_x, game->player_y - 1);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, game->player_x - 1, game->player_y);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, game->player_x, game->player_y + 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}