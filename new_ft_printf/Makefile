# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nammari <nammari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 00:20:25 by nammari           #+#    #+#              #
#    Updated: 2021/07/08 00:41:47 by nammari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=		ft_printf.c chained_list.c digit_sign_and_prefix.c\
			flag_values_fill.c flag_checkers.c\
			specifier_checkers.c utils.c digit_printer.c\
			string_printer.c char_printer.c digit_utils.c \

BOBO	=	ft_printf_bonus/ft_printf_bonus.c \
			ft_printf_bonus/chained_list_bonus.c \
			ft_printf_bonus/flag_checkers_bonus.c\
			ft_printf_bonus/digit_sign_and_prefix_bonus.c\
		    ft_printf_bonus/flag_values_fill_bonus.c\
			ft_printf_bonus/specifier_checkers_bonus.c\
			ft_printf_bonus/utils_bonus.c\
			ft_printf_bonus/digit_printer_bonus.c\
		   	ft_printf_bonus/string_printer_bonus.c\
			ft_printf_bonus/char_printer_bonus.c\
			ft_printf_bonus/digit_utils_bonus.c

CC	=		gcc -c

AR	=		ar

ARFLAGS	=	rc

CFLAGS	=	-Wextra -Wall -Werror

NAME	=	libftprintf.a

OBJS	=	$(SRC:.c=.o)

BONU	=	$(BOBO:.c=.o)

$(NAME):	$(OBJS)
			make -C libft
			mv libft/libft.a libftprintf.a
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)
			ranlib $(NAME)

%.o:		%.c
			$(CC) -o $@ $< $(CFLAGS)

all:		$(NAME)

bonus:		$(BONU)
			make -C libft
			mv libft/libft.a libftprintf.a
			$(AR) $(ARFLAGS) $(NAME) $(BONU)
			ranlib $(NAME)

clean:
			rm -rf $(OBJS) $(BONU)
fclean:		clean
			rm -rf $(NAME)

re:			fclean all
