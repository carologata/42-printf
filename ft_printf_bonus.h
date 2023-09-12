/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cogata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:52:04 by cogata            #+#    #+#             */
/*   Updated: 2023/09/12 09:52:06 by cogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_put_and_count_char(char c);
int		ft_put_and_count_str(char *s);
int		ft_int_to_char(int nb);
int		ft_put_and_count_nbr(int nb, char flag);
int		ft_unsigned_putnbr(unsigned int nb);
size_t	ft_strlen(const char *s);
int		ft_to_base16(unsigned long int nb, char type, int is_sharp);
void	find_flag(va_list *args, const char *format, int *i, int *count);
void	find_format(va_list *args, const char *format, int *i, int *count);
int		ft_printf(const char *format, ...);

#endif
