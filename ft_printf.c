/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:26:59 by cogata            #+#    #+#             */
/*   Updated: 2023/09/04 11:27:00 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    int i;
    va_list args;
    char chr;
    char *str;
    unsigned int hex;
    int integer;
    unsigned int u;

    int teste;

    va_start(args, format);

    i = 0;
    while(format[i])
    {
        //char
        if(format[i] == '%' && format[i + 1] == 'c')
        {
            chr = va_arg(args, int);
            write(1, &chr, 1);
            i = i + 2;
        }
        //string
        else if(format[i] == '%' && format[i + 1] == 's')
        {
            str = va_arg(args, char *);
            ft_putstr(str);
            i = i + 2;
        }
        //pointer address
        else if(format[i] == '%' && format[i + 1] == 'p')
        {
            hex = va_arg(args, unsigned int);
            write(1, "0x", 2);
            ft_base10_to_base16(hex, "0123456789abcdef", 16);
            i = i + 2;
        }
        //decimal (base 10)
        else if(format[i] == '%' && format[i + 1] == 'd')
        {
            integer = va_arg(args, int);
            ft_putnbr(integer);
            i = i + 2;
        }
        //int (data type in the C programming language)
        else if(format[i] == '%' && format[i + 1] == 'i')
        {
            integer = va_arg(args, int);
            ft_putnbr(integer);
            i = i + 2;
        }
        //unsigned int
        else if(format[i] == '%' && format[i + 1] == 'u')
        {
            u = va_arg(args, unsigned int);
            ft_unsigned_putnbr(u);
            i = i + 2;
        }
        //x hexadecimal lowercase
        else if(format[i] == '%' && format[i + 1] == 'x')
        {
            hex = va_arg(args, unsigned int);
            ft_base10_to_base16(hex, "0123456789abcdef", 16);
            i = i + 2;
        }
        //X hexadecimal uppercase
        else if(format[i] == '%' && format[i + 1] == 'X')
        {
            hex = va_arg(args, unsigned int);
            ft_base10_to_base16(hex, "0123456789ABCDEF", 16);
            i = i + 2;
        }
        //%
        else if(format[i] == '%' && format[i + 1] == '%')
        {
            chr = '%';
            write(1, &chr, 1);
            i = i + 2;
        }
        else
        {
            write(1, &format[i], 1);
            i++;
        }  
    }

    teste = va_arg(args, int);

    va_end(args);
    
    return (0);
}

#include <stdio.h>

int main(void)
{
    char ch = 'A';
    char *str;
    int i;
    i = -10;
    float percentage;
    int percentage2;

    str = malloc(6);
    str[0] = 'C';
    str[1] = 'a',
    str[2] = 'r';
    str[3] = 'o';
    str[4] = 'l';
    str[5] = '\0';

    ft_printf("Oi, tudo bem %s? Sua sala é 7%c. Agora são %dh %ih.\n", str, ch, i, i);
    printf("Oi, tudo bem %s? Sua sala é 7%c. Agora são %dh %ih.\n", str, ch, i, i);

    ft_printf("pointer %p\n", str);
    printf("pointer %p\n", str);

    ft_printf("unsigned %u\n", i);  
    printf("unsigned %u\n", i);  

    percentage = 1.58;
    percentage2 = 5;

    // ft_printf("double %d", percentage);
    // printf("double %d", percentage);

    printf("percentage %f%%\n", percentage);
    printf("percentage %lf%%\n", percentage);
    printf("percentage %d%%\n", percentage2);

    printf("percentage 5%%\n");

    ft_printf("percentage 5%%%d OI", i);
}