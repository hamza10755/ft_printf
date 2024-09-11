/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:22:08 by hbelaih           #+#    #+#             */
/*   Updated: 2024/09/11 15:34:31 by hbelaih          ###   ########.fr       */
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

int	print_pointer(void *s)
{
	int				len;
	unsigned long	l;

	l = (unsigned long)s;
	len = 0;
	len += write(1, "0x", 2);
	if (l == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	print_hex(l);
	len += hex_len(l);
	return (l);
}
