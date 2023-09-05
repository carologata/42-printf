
#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_int_to_char(int nb)
{
	int		aux;
	char	c;

	if (nb > 9)
	{
		aux = nb / 10;
		ft_int_to_char(aux);
		c = (nb % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb >= 0 && nb <= 2147483647)
	{
		ft_int_to_char(nb);
	}
	else if (nb < 0 && nb >= -2147483647)
	{
		write(1, "-", 1);
		nb = nb * (-1);
		ft_int_to_char(nb);
	}
}

void ft_unsigned_putnbr(unsigned int nb)
{
	char c;

	if(nb > 9)
	{
		ft_int_to_char(nb/10);
		c = (nb % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

void	ft_base10_to_base16(unsigned int nb, char *base, unsigned int count_base)
{
	int	aux;

	aux = 0;
	if (nb >= count_base)
	{
		aux = nb / count_base;
		ft_base10_to_base16(aux, base, count_base);
		write(1, &base[nb % count_base], 1);
	}
	else
	{
		write(1, &base[nb], 1);
	}
}