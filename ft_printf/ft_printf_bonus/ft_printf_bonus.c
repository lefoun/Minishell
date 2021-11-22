/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:17:01 by nammari           #+#    #+#             */
/*   Updated: 2021/07/08 00:38:43 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//		Functions 4 / 5

bool	is_valid_argument(const char *str)
{
	int	index;

	index = 0;
	while (str[index] && is_primary_flag(str[index]))
		++index;
	is_width_flag(str, &index);
	is_precision_flag(str, &index);
	if (is_specifier(str[index]) || str[index] == '%')
		return (true);
	return (false);
}

int	format_parser(va_list	*ap, const char	*str, t_var_func	*ptr)
{
	int			i;
	int			nb_printed_chars;
	t_var_func	*cur_elem;

	i = 0;
	nb_printed_chars = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_valid_argument(str + i + 1))
		{
			++i;
			while (str[i] && !is_specifier(str[i]) && str[i] != '%')
				++i;
			cur_elem = get_element(ptr, str[i]);
			nb_printed_chars += cur_elem->treat_function(ap, str + i);
		}
		else
		{
			write(1, &str[i], 1);
			++nb_printed_chars;
		}
		++i;
	}
	return (nb_printed_chars);
}

int	treat_percent(va_list	*varlist, const char	*str)
{
	unsigned char		percent;
	t_flag_values		*flag;
	int					printed;

	flag = init_to_zero();
	printed = 0;
	--str;
	percent = '%';
	while (*str && *str != percent)
		--str;
	if (wildcard_width_checker(str))
		flag->width_nb = va_arg(*varlist, int);
	if (flag->width_nb < 0)
	{
		flag->width_nb *= -1;
		flag->left_justify = true;
	}
	get_width(str, 0, flag);
	get_flag_data(str, percent, flag);
	printed = print_char(percent, flag);
	free(flag);
	return (printed);
}

int	ft_printf(const	char	*str, ...)
{
	va_list		args;
	t_var_func	*ptr;
	int			printed_chars;

	va_start(args, str);
	ptr = create_list();
	if (!ptr)
	{
		va_end(args);
		return (error_malloc());
	}
	printed_chars = format_parser(&args, str, ptr);
	va_end(args);
	free_list(ptr);
	return (printed_chars);
}
