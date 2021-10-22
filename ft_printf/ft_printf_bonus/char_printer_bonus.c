/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:58:58 by nammari           #+#    #+#             */
/*   Updated: 2021/07/08 00:49:02 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_char(char mychar, t_flag_values	*flag)
{
	int				i;
	int				width;
	int				printed;
	char			pad;

	i = 0;
	pad = ' ';
	if (flag->pad_zero)
		pad = '0';
	printed = 1;
	if (flag->width_nb > 1)
		printed = flag->width_nb;
	width = 0;
	if (flag->width_nb > 0)
		width = flag->width_nb - 1;
	if (!flag->left_justify)
		while (width-- > 0)
			ft_putchar_fd(pad, 1);
	ft_putchar_fd(mychar, 1);
	while (width-- > 0)
		ft_putchar_fd(pad, 1);
	return (printed);
}

int	treat_char(va_list	*varlist, const char	*str)
{
	char				my_char;
	t_flag_values		*flag;
	int					printed;
	int					format;

	flag = init_to_zero();
	printed = 0;
	format = *str;
	--str;
	while (*str && *str != '%')
		--str;
	if (wildcard_width_checker(str))
		flag->width_nb = va_arg(*varlist, int);
	if (flag->width_nb < 0)
	{
		flag->width_nb *= -1;
		flag->left_justify = true;
	}
	get_width(str, format, flag);
	get_flag_data(str, format, flag);
	my_char = va_arg(*varlist, unsigned int);
	printed = print_char(my_char, flag);
	free(flag);
	return (printed);
}
