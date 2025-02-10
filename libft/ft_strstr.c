/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:07:31 by fmixtur           #+#    #+#             */
/*   Updated: 2025/02/10 12:49:35 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			ptr = &haystack[i];
			while (haystack[i] == needle[j])
			{
				i++;
				j++;
				if (needle[j] == '\0')
					return (ptr);
			}
			i = i - j + 1;
			j = 0;
		}
		i++;
	}
	return (0);
}
