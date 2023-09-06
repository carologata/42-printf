/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:04:42 by cogata            #+#    #+#             */
/*   Updated: 2023/09/06 16:04:46 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BASE16 "0123456789abcdef"

int		ft_put_and_count_char(char c);
int		ft_put_and_count_str(char *s);
int		ft_int_to_char(int nb);
int		ft_put_and_count_nbr(int nb);
int		ft_unsigned_putnbr(unsigned int nb);
size_t	ft_strlen(const char *s);
int		ft_base10_to_base16(unsigned long int nb, char type);
void	find_data_type(va_list *args, const char *format, int *i, int *count);
int		ft_printf(const char *format, ...);

#endif
