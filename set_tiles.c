/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:18:04 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/13 14:18:04 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_mlx *game, void *img, int x, int y)
{
	int	tile_size;

	tile_size = 60;
	mlx_put_image_to_window(game->mlx, game->window,
		img, x * tile_size, y * tile_size);
}

void	set_img_address(t_mlx *game)
{
	game->img->player = "img/player.xpm";
	game->img->collectible = "img/collectible.xpm";
	game->img->exit_open = "img/exit_open.xpm";
	game->img->exit_closed = "img/exit_closed.xpm";
	game->img->wall = "img/wall.xpm";
	game->img->tile = "img/tile.xpm";
}

void	set_tiles(t_mlx *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	if (!game->img)
		return ;
	set_img_address(game);
	find_player_position(game->map, &game->player_x, &game->player_y);
	game->img->width = 60;
	game->img->height = 60;
	game->img->img_player = mlx_xpm_file_to_image(game->mlx,
			game->img->player,
			&game->img->width, &game->img->height);
	game->img->img_collectible = mlx_xpm_file_to_image(game->mlx,
			game->img->collectible,
			&game->img->width, &game->img->height);
	game->img->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			game->img->exit_open,
			&game->img->width, &game->img->height);
	game->img->img_exit_closed = mlx_xpm_file_to_image(game->mlx,
			game->img->exit_closed,
			&game->img->width, &game->img->height);
	game->img->img_wall = mlx_xpm_file_to_image(game->mlx,
			game->img->wall, &game->img->width, &game->img->height);
	game->img->img_tile = mlx_xpm_file_to_image(game->mlx,
			game->img->tile, &game->img->width, &game->img->height);
	render_map(game);
}

void	render_map(t_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, game->img->img_tile, x, y);
			if (game->map[y][x] == '1')
				render_tile(game, game->img->img_wall, x, y);
			else if (game->map[y][x] == 'P')
				render_tile(game, game->img->img_player, x, y);
			else if (game->map[y][x] == 'C')
				render_tile(game, game->img->img_collectible, x, y);
			else if (game->map[y][x] == 'E' && game->collectible_count == 0)
				render_tile(game, game->img->img_exit_open, x, y);
			else if (game->map[y][x] == 'E')
				render_tile(game, game->img->img_exit_closed, x, y);
			x++;
		}
		y++;
	}
}
