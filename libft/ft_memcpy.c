/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/07/2024 17:07:02 by fmixtur           #+#    #+#             */
/*   Updated: 22/07/2024 17:51:11 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char		*a;
	const unsigned char	*b;

	if (!dest && !src)
		return (NULL);
	a = dest;
	b = (const unsigned char *)src;
	while (n--)
	{
		*a = *b;
		a++;
		b++;
	}
	return (dest);
}
