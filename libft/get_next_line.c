/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:30:40 by fmixtur           #+#    #+#             */
/*   Updated: 2025/01/24 17:29:34 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;
	int				eof;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	eof = 0;
	while (!line)
	{
		stash = read_file(fd, stash, &eof);
		if (!stash)
			return (NULL);
		line = find_newline(&stash, eof);
	}
	if (line && *line == '\0')
	{
		free (line);
		line = NULL;
	}
	return (line);
}

char	*read_file(int fd, char *stash, int *eof)
{
	char	*buffer;
	char	*temp;
	size_t	bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0 || bytes_read < BUFFER_SIZE)
		*eof = 1;
	if (bytes_read > BUFFER_SIZE)
	{
		ft_freed(buffer, stash);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	if (stash)
	{
		temp = ft_strjoin(stash, buffer);
		free(stash);
	}
	else
		temp = ft_strdup(buffer);
	free(buffer);
	return (temp);
}

char	*find_newline(char **str, int eof)
{
	char	*pos;
	char	*line;
	char	*new_stash;
	int		len;

	pos = ft_strchr(*str, '\n');
	if (!pos && eof)
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (line);
	}
	if (pos == NULL)
		return (NULL);
	len = pos - *str + 1;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *str, len + 1);
	new_stash = ft_strdup(pos + 1);
	free(*str);
	*str = new_stash;
	return (line);
}

void	ft_freed(char *s1, char *s2)
{
	free(s1);
	free(s2);
}
