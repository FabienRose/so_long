/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:19:55 by fmixtur           #+#    #+#             */
/*   Updated: 2024/07/24 09:23:10 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t size)
{
	char		*ptr;
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return (haystack);
	while (haystack[i] && i < size)
	{
		if (haystack[i] == needle[j])
		{
			ptr = &haystack[i];
			while (haystack[i] == needle[j++] && i < size)
			{
				i++;
				if (needle[j] == '\0')
					return (ptr);
			}
			i = i - j + 1;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
