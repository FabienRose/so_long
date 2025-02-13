/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:20:43 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/13 14:30:02 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate_map(char **map, int rows)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc((rows + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			while (i > 0)
				free(new_map[--i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[rows] = NULL;
	return (new_map);
}

void	find_player_position(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

int	check_remaining_elements(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				return (FALSE);
			y++;
		}
		x++;
	}
	return (TRUE);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	fill_map(int fd, char **map)
{
	int		rows;
	char	*line;

	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[rows++] = ft_strdup(clean_line(line));
		free(line);
		line = get_next_line(fd);
	}
	map[rows] = NULL;
	return (rows);
}
