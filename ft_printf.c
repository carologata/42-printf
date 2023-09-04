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
    int j;
    va_list args;
    int chr;
    char *str;
    unsigned int p;
    double decimal;
    int integer;

    va_start(args, format);

    i = 0;
    while(format[i])
    {
        //c
        if(format[i] == '%' && format[i + 1] == 'c')
        {
            chr = va_arg(args, int);
            write(1, &chr, 1);
            i = i + 2;
        }
        //s
        else if(format[i] == '%' && format[i + 1] == 's')
        {
            str = va_arg(args, char *);
            j = 0;
            while(str[j] != '\0')
            {
                write(1, &str[j], 1);
                j++;
            }
            i = i + 2;
        }
        //p
        else if(format[i] == '%' && format[i + 1] == 'p')
        {
            p = (unsigned int) va_arg(args, int);
            ft_base10_to_base16(p, "0123456789ABCDEF", 16);
            i = i + 2;
        }
        //d
        else if(format[i] == '%' && format[i + 1] == 'd')
        {
            decimal = va_arg(args, double);
            str = ft_itoa(decimal);
            j = 0;
            while(str[j] != '\0')
            {
                write(1, &str[j], 1);
                j++;
            }
            i = i + 2;
        }
        //i
        else if(format[i] == '%' && format[i + 1] == 'i')
        {
            integer = va_arg(args, int);
            str = ft_itoa(integer);
            j = 0;
            while(str[j] != '\0')
            {
                write(1, &str[j], 1);
                j++;
            }
            i = i + 2;
        }
        //u
        else if(format[i] == '%' && format[i + 1] == 'u')
        {

        }
        //x
        else if(format[i] == '%' && format[i + 1] == 'x')
        {

        }
        //X
        else if(format[i] == '%' && format[i + 1] == 'X')
        {

        }
        //%
        else if(format[i] == '%' && format[i + 1] == '%')
        {

        }
        else
        {
            write(1, &format[i], 1);
            i++;
        }  
    }
    
    return (0);
}

#include <stdio.h>

int main(void)
{
    char ch = 'A';
    char *str;
    double i;
    i = 10.5;

    str = malloc(6);
    str[0] = 'C';
    str[1] = 'a',
    str[2] = 'r';
    str[3] = 'o';
    str[4] = 'l';
    str[5] = '\0';

    ft_printf("Oi, tudo bem %s? Sua sala é 7%c. Agora são %dh.\n", str, ch, i);

    ft_printf("pointer %p\n", str);

}