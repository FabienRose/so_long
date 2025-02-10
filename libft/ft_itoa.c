/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:41:30 by fmixtur           #+#    #+#             */
/*   Updated: 2024/07/24 12:41:51 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intsize(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	inttostring(char	*str, int len, int n)
{
	str[len] = '\0';
	while (n > 0)
	{
		str[len-- - 1] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		minus;
	int		len;
	int		i;
	char	*str;

	minus = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		minus = 1;
		n = -n;
	}
	len = intsize(n);
	str = malloc(sizeof(char) * (len + minus + 1));
	if (!str)
		return (NULL);
	if (minus)
		str[i] = '-';
	i = len + minus;
	inttostring(str, i, n);
	return (str);
}
