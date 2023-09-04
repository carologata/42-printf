

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

long long	ft_count_divider(long nb);
char	*ft_init_str(long nb, char *res, int count, int is_negative);
int	ft_count_num(long nb);
char	*ft_itoa(int n);
void	ft_base10_to_base16(unsigned int nb, char *base, unsigned int count_base);
int ft_printf(const char *format, ...);

#endif
