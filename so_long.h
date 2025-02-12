/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:33:12 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/12 23:33:46 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "minilibx_linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_img
{
	char	*player;
	char	*tile;
	char	*wall;
	char	*collectible;
	char	*exit_open;
	char	*exit_closed;
	void	*img_tile;
	void	*img_player;
	void	*img_exit_open;
	void	*img_exit_closed;
	void	*img_wall;
	void	*img_collectible;
	void	*img_unlock;
	int		height;
	int		width;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	char	**map;
	int		height;
	int		width;
	t_img	*img;
	int		player_x;
	int		player_y;
	int		collectible_count;
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

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

char	**load_map(const char *filename);
int		is_map_valid(char **map);
void	flood_fill(char **map, int x, int y);
int		fill_map(int fd, char **map);
char	*clean_line(char *line);
void	cleanup(t_mlx *game);

char	**duplicate_map(char **map, int rows);
void	find_player_position(char **map, int *x, int *y);
int		check_remaining_elements(char **map);
void	free_map(char **map);

void	render_map(t_mlx *mlx_data);
void	set_tiles(t_mlx *game);

void	key_binds(t_mlx *game);
int		count_collectibles(char **map);

void	cleanup(t_mlx *game);


#endif