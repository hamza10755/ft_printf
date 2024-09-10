/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzabillah <hamzabillah@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 00:16:19 by hamzabillah       #+#    #+#             */
/*   Updated: 2024/09/11 01:13:41 by hamzabillah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

int ft_putchar(int c)
{
    return write(1, &c, 1);
}
// we took them as an integers to write the characters and iterate the bytes 
int ft_putstr(char *s)
{
    int i;

    i = 0;
    while (*s)
    {
        ft_putchar((int)*s);
        i++;
        s++;
    }
    return (i); // cause we are iterating the bytes
}

int printdigit(long n, int base)
{
    int i;
    char s[16];

    s[16] = "0123456789abcdef";    
    if(n < 0)
    {
        ft_putchar('-');
        return printdigit(-n, base) + 1; // for the minus
    }
    else if (n < base)
        return ft_putchar(s[n]);
    else
    {
        i = printdigit(n / base, base);
        return i + printdigit(n % base, base);
}
}
int printdigit_upper(long n, int base)
{
    int i;
    char s[16];

    s[16] = "0123456789ABCDEF";        
    if (n < base)
        return ft_putchar(s[n]);
    else
    {
        i = printdigit_upper(n / base, base);
        return i + printdigit_upper(n % base, base);
    }
}

