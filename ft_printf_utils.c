
#include "ft_printf.h"

long long	ft_count_divider(long nb)
{
	long long	divider;

	if (nb == 0)
		return (1);
	divider = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		divider = divider * 10;
	}
	divider = divider / 10;
	return (divider);
}

char	*ft_init_str(long nb, char *res, int count, int is_negative)
{
	int		i;
	long	divider;

	divider = ft_count_divider(nb);
	i = 0;
	if (is_negative == 1)
	{
		res[0] = '-';
		i++;
	}
	while (i < count)
	{
		res[i] = (nb / divider) + '0';
		nb = nb % divider;
		divider = divider / 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_count_num(long nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		count;
	char	*res;
	int		is_negative;

	nb = n;
	is_negative = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		count = ft_count_num(nb) + 1;
		is_negative = 1;
	}
	else if (nb == 0)
		count = 1;
	else
		count = ft_count_num(nb);
	res = malloc((count + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_init_str(nb, res, count, is_negative);
	return (res);
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