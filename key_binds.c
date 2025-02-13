/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:08:18 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/13 14:15:39 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_player_position(t_mlx *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
}

int	move_player(t_mlx *game, int new_x, int new_y)
{
	static int	moves = 0;

	if (game->map[new_y][new_x] == '1')
		return (FALSE);
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectible_count--;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectible_count == 0)
		{
			ft_printf("You win! Total moves: %d\n", moves + 1);
			cleanup(game);
			exit(0);
		}
		ft_printf("Collect all collectibles before exiting!\n");
		return (FALSE);
	}
	new_player_position(game, new_x, new_y);
	moves++;
	ft_printf("Moves: %d\n", moves);
	render_map(game);
	return (TRUE);
}

int	handle_keypress(int keycode, t_mlx *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_ESC)
	{
		cleanup(game);
		exit(0);
	}
	else if (keycode == KEY_W)
		new_y--;
	else if (keycode == KEY_S)
		new_y++;
	else if (keycode == KEY_A)
		new_x--;
	else if (keycode == KEY_D)
		new_x++;
	if (new_x != game->player_x || new_y != game->player_y)
		move_player(game, new_x, new_y);
	return (FALSE);
}

int	cross_click(t_mlx *game)
{
	cleanup(game);
	exit(0);
}

void	key_binds(t_mlx *game)
{
	mlx_hook(game->window, 2, 1L << 0, &handle_keypress, game);
	mlx_hook(game->window, 17, 0, &cross_click, game);
}
