/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:39:19 by fmixtur           #+#    #+#             */
/*   Updated: 2024/07/24 12:39:35 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	totrim(char c, char const *set)
{
	while (*set)
	{
		if ((char)*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	trim_begin(const	char *s, const	char *set)
{
	int	begin;

	begin = 0;
	while (totrim(*s, set))
	{
		begin++;
		s++;
	}
	return (begin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		begin;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen((char *)s1);
	begin = trim_begin(s1, set);
	if (begin == len)
		return (ft_strdup(""));
	i = 1;
	end = 0;
	while (totrim(s1[len - i++], set))
		end++;
	len -= begin + end;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}
