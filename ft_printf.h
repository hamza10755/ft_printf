/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:37:10 by hbelaih           #+#    #+#             */
/*   Updated: 2024/09/12 17:46:50 by hbelaih          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include	<unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	printdigit(long n, int base);
int	printdigit_upper(unsigned long n, int base);
int	print_pointer(unsigned long n);
int	print_unsigned(unsigned int num);
int ft_printf(const char *format, ...);

#endif