/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 00:16:19 by hamzabillah       #+#    #+#             */
/*   Updated: 2024/09/11 15:28:57 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		ft_putchar((int)*s);
		i++;
		s++;
	}
	return (i);
}

int	printdigit(long n, int base)
{
	int		i;
	const char	*s;

	s = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		return (printdigit(-n, base) + 1);
	}
	else if (n < (long) base)
		return (ft_putchar(s[n]));
	else
	{
		i = printdigit(n / base, base);
		return (i + printdigit(n % base, base));
	}
}

int	printdigit_upper(unsigned long n, int base)
{
	int		i;
	const char	*s;

	s = "0123456789ABCDEF";
	if (n < (unsigned long) base)
		return (ft_putchar(s[n]));
	else
	{
		i = printdigit_upper(n / base, base);
		return (i + printdigit_upper(n % base, base));
	}
}

int	print_percent(void)
{
	return write(1, "%", 1);
}