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

void	find_data_type(va_list	*args, const char *format, int *i, int *count)
{
	if (format[*i] == 'c')
		*count += ft_putchar(va_arg(*args, int));
	else if (format[*i] == 's')
		*count += ft_putstr(va_arg(*args, char *));
	else if (format[*i] == 'p')
		*count += ft_base10_to_other_base(va_arg(*args, unsigned int), format[*i]);
	else if (format[*i] == 'd')
		*count += ft_putnbr(va_arg(*args, int));
	else if (format[*i] == 'i')
		*count += ft_putnbr(va_arg(*args, int));
	else if (format[*i] == 'u')
		*count += ft_unsigned_putnbr(va_arg(*args, unsigned int));
	else if (format[*i] == 'x')
		*count += ft_base10_to_other_base(va_arg(*args, unsigned int), format[*i]);
	else if (format[*i] == 'X')
		*count += ft_base10_to_other_base(va_arg(*args, unsigned int), format[*i]);
	else if (format[*i] == '%')
		*count += ft_putchar('%');
	else
    {
		*i -= 1;
        *count += ft_putchar(format[*i]);
        *i += 1;
    }
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
    int count;

    count = 0;
    if(format == NULL)
        return (-1);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
            find_data_type(&args, format, &i, &count);
		}
		else
        {
			ft_putchar(format[i]);
            count++;
        }
        i++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	char ch = 'A';
	char *str;
	int i;
	i = 456;
	float percentage;
	int percentage2;
    int count;

    count = 0;

	str = malloc(6);
	str[0] = 'C';
	str[1] = 'a',
	str[2] = 'r';
	str[3] = 'o';
	str[4] = 'l';
	str[5] = '\0';


	percentage = 1.58;
	percentage2 = 5;

    count = ft_printf("p: %p\n", str);
	printf("p: %p\n", str);
	printf("count = %d\n\n", count);
	//p: 0xa8c2a0n		12

    count = ft_printf("Oi, tudo bem %s? Sua sala e 7%c. Agora sao %dh %ih.\n", str, ch, i, i);
	printf("Oi, tudo bem %s? Sua sala e 7%c. Agora sao %dh %ih.\n", str, ch, i, i);
    printf("count = %d\n\n", count);
	//Oi, tudo bem Carol? Sua sala e 7A. Agora sao 456h 456h.n		56

    count = ft_printf("unsigned: %u\n", i);
	printf("unsigned: %u\n", i);
	printf("count = %d\n\n", count);
	//unsigned: 456n		14

	count = ft_printf("hex: %x\n", i);
	ft_printf("hex: %x\n", i);
	printf("count = %d\n\n", count);
	//hex: 1c8n		9

	count = ft_printf("percentage %%\n");
	printf("percentage %%\n");
	printf("count = %d\n\n", count);
	//percentage %n		13

	//compile with -w
    count = ft_printf("f%jk\n", i);
	printf("f%jk\n", i);
	printf("count = %d\n\n", count);
	//f%k	4

}