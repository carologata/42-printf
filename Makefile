# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cogata <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 16:05:22 by cogata            #+#    #+#              #
#    Updated: 2023/09/06 16:05:24 by cogata           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

MANDATORY_SRC = ft_printf.c ft_printf_utils.c

MANDATORY_OBJ = $(MANDATORY_SRC:%.c=%.o)

BONUS_SRC = ft_printf_bonus.c ft_printf_utils_bonus.c

BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)

%.o: %.c ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

bonus: $(BONUS_OBJ)

norm:
	norminette -R CheckForbiddenSourceHeader $(MANDATORY_SRC) ft_printf.h

clean: 
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
