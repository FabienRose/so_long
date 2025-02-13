/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:57:54 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/13 14:06:29 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

void	set_window_size(t_mlx *game)
{
	int	rows;
	int	cols;

	rows = 0;
	while (game->map[rows])
		rows++;
	cols = ft_strlen(game->map[0]);
	game->width = 60 * cols;
	game->height = 60 * rows;
}

int	map_init(char *map_name, t_mlx *game)
{
	if (!map_name || !ft_strstr(map_name, ".ber"))
	{
		ft_printf("Need a .ber map file.\n");
		return (TRUE);
	}
	game->map = load_map(map_name);
	if (!is_map_valid(game->map))
	{
		ft_printf("Map is not conform.\n");
		cleanup(game);
		return (TRUE);
	}
	return (FALSE);
}

int	main(int ac, char **argv)
{
	t_mlx	game;

	(void)ac;
	ft_bzero(&game, sizeof(game));
	if (map_init(argv[1], &game))
		return (TRUE);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (TRUE);
	set_window_size(&game);
	game.window = mlx_new_window(game.mlx, game.width,
			game.height, "Ninja Shuriken");
	game.collectible_count = count_collectibles(game.map);
	set_tiles(&game);
	key_binds(&game);
	mlx_loop(game.mlx);
	return (0);
}
