/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:27:09 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/12 10:51:43 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(const char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	*clean_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	return (line);
}

char	**load_map(const char *filename)
{
	int		fd;
	int		line_count;
	char	**map;

	line_count = count_lines(filename);
	if (line_count <= 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	fill_map(fd, map);
	close(fd);
	return (map);
}
