/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_sign_and_prefix_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:00:00 by nammari           #+#    #+#             */
/*   Updated: 2021/07/08 00:38:43 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//		2 / 5

void	disp_sign(char format, t_flag_values *flag, char *string)
{
	if (format == 'd' || format == 'i' || format == 'u')
	{
		if (flag->disp_sign || *string == '-')
			ft_putchar_fd(*string, 1);
		else if (flag->disp_space)
			ft_putchar_fd(' ', 1);
		if ((flag->disp_sign || *string == '-')
			|| (flag->disp_space))
			flag->prefix_char_count = 1;
	}
	else if (ft_ishex(format) && (string[1] != 0 && string[1] != '0')
		&& flag->disp_hex_prefix)
	{
		if (format == 'x')
			ft_putstr("0x");
		else if (format == 'X')
			ft_putstr("0X");
		flag->prefix_char_count = 2;
	}
	else if (format == 'p')
	{
		ft_putstr("0x");
		flag->prefix_char_count = 2;
	}
}

int	count_digit_prefix(t_flag_values *flag, char format, char *string)
{
	int	len;

	len = 0;
	if (ft_ishex(format) && format != 'p')
	{
		if ((flag->disp_hex_prefix) && (string[1] != 0 && string[1] != '0'))
			len = len + 2;
	}
	else if (flag->disp_space)
		++len;
	else if (flag->disp_sign)
		++len;
	else if (*string == '-')
		++len;
	else if (format == 'p')
		len = len + 2;
	return (len);
}
