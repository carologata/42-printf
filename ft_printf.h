

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_int_to_char(int nb);
int	ft_putnbr(int nb);
int	ft_unsigned_putnbr(unsigned int nb);
void ft_base10_to_other_base(unsigned int nb, char type, int **count);
int	ft_printf(const char *format, ...);

#endif
