/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:22:08 by hbelaih           #+#    #+#             */
/*   Updated: 2024/09/12 18:21:11 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	print_hex(unsigned long num)
{
	const char	*s;

	s = "0123456789abcdef";
	if (num >= 16)
		print_hex(num / 16);
	ft_putchar(s[num % 16]);
}

int	print_pointer(unsigned long l)
{
	int				len;

	len = 0;
	if (l == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	else
		len += write(1, "0x", 2);
	print_hex(l);
	len += hex_len(l);
	return (len);
}
