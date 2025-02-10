/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:24:59 by fmixtur           #+#    #+#             */
/*   Updated: 2024/07/24 00:24:59 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned char			*a;
	const unsigned char		*b;
	int						i;

	a = dest;
	b = src;
	i = 0;
	if (a < b)
	{
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	}
	else if (a > b)
	{
		while (0 < n)
		{
			a[n - 1] = b[n - 1];
			n--;
		}
	}
	return (dest);
}
