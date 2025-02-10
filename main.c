/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace.json                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:16:37 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/10 14:16:37 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

void	cleanup(t_mlx *mlx_data)
{
	if (mlx_data->window)
		mlx_destroy_window(mlx_data->mlx, mlx_data->window);
	if (mlx_data->mlx)
	{
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
	}
}

int	handle_keypress(int keycode, t_mlx *mlx_data)
{
	if (keycode == 65307)
	{
		cleanup(mlx_data);
		exit(0);
	}
	return (FALSE);
}

int	main(int ac, char **argv)
{
	t_mlx	mlx_data;
	char	**map;

	(void)ac;
	(void)map;
	if (!argv[1] || !ft_strstr(argv[1], ".ber"))
	{
		ft_printf("Need a .ber map file.\n");
		return (0);
	}
	map = load_map(argv[1]);
	ft_printf("Is Map Valid? : %d\n", is_map_valid(map));
	mlx_data.mlx = mlx_init();
	if (!mlx_data.mlx)
		return (TRUE);
	mlx_data.window = mlx_new_window(mlx_data.mlx, 800, 600, "Hello world!");
	mlx_hook(mlx_data.window, 2, 1L << 0, handle_keypress, &mlx_data);
	mlx_loop(mlx_data.mlx);
	//remember to FREE THE MAP
	return (0);
}
