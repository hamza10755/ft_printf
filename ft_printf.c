/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:36:01 by hamzabillah       #+#    #+#             */
/*   Updated: 2024/09/11 01:12:15 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int print_format(char sp, va_list ap)
{
    int count;

    count = 0;
    if (sp == 'c')
       count += ft_putchar(va_arg(ap, int));// took an int because of the integer representation on the character is accessible by the va_arg
    else if (sp == 's')
        count += ft_putstr(va_arg(ap, char *));
    else if(sp == 'd')
        count += printdigit((long)va_arg(ap, int), 10);// casted to long to contain every case for the decimal and the hexadecimal 
    else if (sp == 'x')
        count += printdigit((long)va_arg(ap,unsigned int), 16);
    else if (sp == 'X')
        count += printdigit_upper((long)va_arg(ap, unsigned int), 16);
    else
        count += write(1, &sp, 1);
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list ap;// the list
    int count;

    va_start(ap, format);
    count = 0;
    while (*format)
    {
        if (*format == '%')
            count += print_format(*(++format), ap);
        else
            count += write(1, format, 1);
        ++format;
    }
    va_end(ap);
    return (count);
}

int main ()
{
    int count;

    count = ft_printf("%x\n", 42);
    ft_printf("the chars written are %d\n", count);
}