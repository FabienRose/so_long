/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmixtur <fmixtur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:37:05 by fmixtur           #+#    #+#             */
/*   Updated: 2024/12/16 22:38:06 by fmixtur          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*select_param(const char *str, va_list args, int *len)
{
	str++;
	if (*str == 'd' || *str == 'i')
		print_string(args, len, 1);
	if (*str == 'u')
		print_unsigned(va_arg(args, unsigned int), len);
	else if (*str == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*len)++;
	}
	else if (*str == 's')
		print_string(args, len, 0);
	if (*str == 'x')
		print_hex(va_arg(args, unsigned int), len, 0);
	if (*str == 'X')
		print_hex(va_arg(args, unsigned int), len, 1);
	if (*str == 'p')
		print_address(va_arg(args, unsigned long), len, 1);
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		(*len)++;
	}
	return (str);
}

void	print_hex(unsigned int n, int *len, int upcase)
{
	if (n >= 16)
		print_hex(n / 16, len, upcase);
	if (upcase)
		ft_putchar_fd("0123456789ABCDEF"[n % 16], 1);
	else
		ft_putchar_fd("0123456789abcdef"[n % 16], 1);
	(*len)++;
}

void	print_string(va_list args, int *len, int isint)
{
	char	*s;

	if (isint)
		s = ft_itoa(va_arg(args, int));
	else
		s = va_arg(args, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*len) += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		(*len) += ft_strlen(s);
	}
	if (isint)
		free(s);
}

void	print_unsigned(unsigned int n, int *len)
{
	if (n >= 10)
		print_unsigned(n / 10, len);
	ft_putchar_fd("0123456789"[n % 10], 1);
	(*len)++;
}

void	print_address(unsigned long n, int *len, int flag)
{
	if (n == 0)
	{
		ft_putstr_fd("0x0", 1);
		(*len) += 3;
		return ;
	}
	if (flag)
	{
		ft_putstr_fd("0x", 1);
		(*len) += 2;
		flag = 0;
	}
	if (n >= 16)
		print_address(n / 16, len, 0);
	ft_putchar_fd("0123456789abcdef"[n % 16], 1);
	(*len)++;
}
