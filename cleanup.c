/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:12:20 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/12 23:20:32 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_mlx *game)
{
	if (!game || !game->img)
		return ;
	if (game->img->img_player)
		mlx_destroy_image(game->mlx, game->img->img_player);
	if (game->img->img_tile)
		mlx_destroy_image(game->mlx, game->img->img_tile);
	if (game->img->img_wall)
		mlx_destroy_image(game->mlx, game->img->img_wall);
	if (game->img->img_collectible)
		mlx_destroy_image(game->mlx, game->img->img_collectible);
	if (game->img->img_exit_open)
		mlx_destroy_image(game->mlx, game->img->img_exit_open);
	if (game->img->img_exit_closed)
		mlx_destroy_image(game->mlx, game->img->img_exit_closed);
}

void	cleanup(t_mlx *game)
{
	if (game->img)
	{
		destroy_images(game);
		free(game->img);
		game->img = NULL;
	}
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
}
