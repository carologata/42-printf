
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_int_to_char(int nb)
{
	int		aux;
	char	c;
	int		count;

	count = 0;
	if (nb > 9)
	{
		aux = nb / 10;
		count += ft_int_to_char(aux);
		c = (nb % 10) + '0';
		count += write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	else if (nb >= 0 && nb <= 2147483647)
	{
		count += ft_int_to_char(nb);
	}
	else if (nb < 0 && nb >= -2147483647)
	{
		count += write(1, "-", 1);
		nb = nb * (-1);
		count += ft_int_to_char(nb);
	}
	return (count);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb > 9)
	{
		count += ft_unsigned_putnbr(nb / 10);
		c = (nb % 10) + '0';
		count += write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_base10_to_other_base(unsigned int nb, char type)
{
	int				aux;
	char			*base;
	unsigned int	count_base;
	int				count;

	base = "0123456789abcdef";
	count_base = 16;
	aux = 0;
	count = 0;
	if (nb >= count_base)
	{
		aux = nb / count_base;
		count += ft_base10_to_other_base(aux, type);
		count += write(1, &base[nb % count_base], 1);
	}
	else
	{
		if (type == 'p')
			count += write(1, "0x", 2);
		count += write(1, &base[nb], 1);
	}
	return (count);
}
