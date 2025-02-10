/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:44:42 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/10 12:44:49 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c, t_map_info *info)
{
	if (c == 'P')
		info->player++;
	else if (c == 'E')
		info->exit++;
	else if (c == 'C')
		info->collectibles++;
	else if (c != '0' && c != '1')
		return (FALSE);
	return (TRUE);
}

int	is_border_valid(char *line, int len, int is_top_or_bottom)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ((is_top_or_bottom && line[i] != '1')
			|| (!is_top_or_bottom && (line[0] != '1' || line[len - 1] != '1')))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	validate_map_content(char **map, t_map_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) != info->cols
			|| !is_border_valid(map[i], info->cols, (i == 0
					|| i == info->rows - 1)))
			return (FALSE);
		j = -1;
		while (map[i][++j])
			if (!is_valid_char(map[i][j], info) && map[i][j] != '\0')
				return (FALSE);
	}
	return (TRUE);
}

int	valid_path(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
				break ;
			y++;
		}
		if (map[x][y] == 'P')
			break ;
		x++;
	}
	flood_fill(map, x, y);
	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E' || map[x][y] == 'C')
				return (FALSE);
			y++;
		}
		x++;
	}
	return (TRUE);
}

int	is_map_valid(char **map)
{
	t_map_info	info;

	if (!map || !map[0])
		return (FALSE);
	ft_memset(&info, 0, sizeof(t_map_info));
	info.rows = 0;
	while (map[info.rows])
		info.rows++;
	info.cols = ft_strlen(map[0]);
	if (!validate_map_content(map, &info))
		return (FALSE);
	return (info.player == 1
		&& info.exit >= 1 && info.collectibles >= 1 && valid_path(map));
}
