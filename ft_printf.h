

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putstr(char *str);
void	ft_int_to_char(int nb);
void	ft_putnbr(int nb);
void ft_unsigned_putnbr(unsigned int nb);
void	ft_base10_to_base16(unsigned int nb, char *base, unsigned int count_base);
int ft_printf(const char *format, ...);

#endif
