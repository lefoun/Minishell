/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_values_fill_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:13:13 by nammari           #+#    #+#             */
/*   Updated: 2021/07/08 00:38:43 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//		4 / 5 functions

t_flag_values	*init_to_zero(void)
{
	t_flag_values	*flag;

	flag = malloc(sizeof(*flag));
	if (!flag)
		return (NULL);
	flag->left_justify = false;
	flag->disp_sign = false;
	flag->disp_space = false;
	flag->disp_hex_prefix = false;
	flag->pad_zero = false;
	flag->sign_printed = false;
	flag->width_nb = 0;
	flag->precision_nb = -1;
	flag->prefix_char_count = 0;
	return (flag);
}

void	get_flag_data(const char	*str, char format, t_flag_values	*flag)
{
	while (str && *str != '%')
		--str;
	if (*str == '%')
		++str;
	while (*str && *str != format && *str != '.' && *str != '%')
	{
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			flag->pad_zero = true;
		else if (*str == '-')
			flag->left_justify = true;
		else if (*str == '+')
			flag->disp_sign = true;
		else if (*str == ' ')
			flag->disp_space = true;
		else if (*str == '#')
			flag->disp_hex_prefix = true;
		++str;
	}
	if (flag->pad_zero && flag->left_justify)
		flag->pad_zero = false;
}

void	get_width(const char	*str, char format, t_flag_values	*flag)
{
	while (str && *str != '%')
		--str;
	while (*str && *str != format && *str != '.' && flag->width_nb == 0)
	{
		++str;
		if (ft_isdigit(*str) && *str != '0')
		{
			flag->width_nb = ft_atoi(str);
			if (flag->width_nb < 0)
			{
				flag->width_nb = 0;
			}
			break ;
		}
		else if (*str == '%')
			break ;
	}
}

void	get_precision(const char	*str, char format, t_flag_values	*flag)
{
	while (*str != '%')
		--str;
	while (*str && *str != format && *str != '.')
		++str;
	if (*str == '.' && flag->precision_nb == -1 && *(str + 1) != '*')
	{
		++str;
		if (*str == format)
		{
			flag->precision_nb = 0;
			return ;
		}
		else if (ft_atoi(str) < 0)
			flag->precision_nb = -1;
		else
			flag->precision_nb = ft_atoi(str);
	}
}
