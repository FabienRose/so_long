/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 22/07/2024 14:55:12 by fmixtur           #+#    #+#             */
/*   Updated: 23/07/2024 10:01:25 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	totlen;
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen((char *)src);
	if (size <= destlen)
		return (size + srclen);
	totlen = destlen + srclen;
	i = destlen;
	while (*src && i < size - 1)
	{
		dest[i++] = *src++;
	}
	dest[i] = '\0';
	return (totlen);
}
