/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:04:13 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/07 17:04:13 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "minilibx_linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_map_info
{
	int	rows;
	int	cols;
	int	player;
	int	exit;
	int	collectibles;
}		t_map_info;

# define TRUE 1
# define FALSE 0

char	**load_map(const char *filename);
int		is_map_valid(char **map);
void	flood_fill(char **map, int x, int y);

#endif