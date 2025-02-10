/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:00:13 by fmixtur           #+#    #+#             */
/*   Updated: 2024/11/28 15:13:50 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c, char sep)
{
	return (c == sep || c == '\0');
}

static int	skip_quotes(const char *s, char quote)
{
	int	i;

	i = 1;
	while (s[i] && s[i] != quote)
		i++;
	if (s[i] == quote)
		i++;
	return (i);
}

static int	count_words(const char *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && is_whitespace(*s, sep))
			s++;
		if (*s)
		{
			if (*s == '\'' || *s == '"')
				s += skip_quotes(s, *s);
			else
			{
				while (*s && !is_whitespace(*s, sep)
					&& *s != '\'' && *s != '"')
					s++;
			}
			count++;
		}
	}
	return (count);
}

static char	*extract_word(const char **s, char sep)
{
	char	*word;
	int		len;
	char	quote;

	len = 0;
	if (**s == '\'' || **s == '"')
	{
		quote = *(*s)++;
		while ((*s)[len] && (*s)[len] != quote)
			len++;
		word = ft_substr(*s, 0, len);
		*s += len + ((*s)[len] == quote);
	}
	else
	{
		while ((*s)[len] && !is_whitespace((*s)[len], sep) &&
			(*s)[len] != '\'' && (*s)[len] != '"')
			len++;
		word = ft_substr(*s, 0, len);
		*s += len;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_whitespace(*s, c))
			s++;
		if (*s)
			result[i++] = extract_word(&s, c);
	}
	result[i] = NULL;
	return (result);
}
