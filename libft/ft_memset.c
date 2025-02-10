/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:21:37 by fmixtur           #+#    #+#             */
/*   Updated: 2024/07/24 00:23:09 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (n--)
	{
		ptr[i++] = c;
	}
	return (ptr);
}
