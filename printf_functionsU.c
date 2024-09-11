/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functionsU.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:58:56 by hbelaih           #+#    #+#             */
/*   Updated: 2024/09/11 15:33:01 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	put_unsigned(unsigned int n)
{
	if (n >= 10)
		put_unsigned(n / 10);
	ft_putchar((n % 10) + 0);
}

static int	unsigned_len(unsigned int num)
{
	int	n;

	n = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		n++;
		num /= 10;
	}
	return (n);
}

int	print_unsigned(unsigned int num)
{
	put_unsigned(num);
	return (unsigned_len(num));
}