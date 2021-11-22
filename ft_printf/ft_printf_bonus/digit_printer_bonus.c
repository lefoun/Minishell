/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_printer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:01:06 by nammari           #+#    #+#             */
/*   Updated: 2021/11/22 18:47:20 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	treat_digit(va_list	*varlist, const char	*str)
{
	t_flag_values		*flag;
	t_type_holder		*my_type;
	int					printed;

	flag = init_to_zero();
	my_type = malloc(sizeof(t_type_holder));
	if (!my_type || !flag)
		return (error_malloc());
	if (wildcard_width_checker(str))
		flag->width_nb = va_arg(*varlist, int);
	if (wildcard_precision_checker(str))
		flag->precision_nb = va_arg(*varlist, int);
	else
		get_precision(str, *str, flag);
	if (*str == 'd' || *str == 'i' )
		my_type->digit = va_arg(*varlist, int);
	else if (*str == 'p')
		my_type->ul_digit = va_arg(*varlist, unsigned long long);
	else
		my_type->ul_digit = va_arg(*varlist, unsigned int);
	printed = print_digit(str, my_type, flag);
	free(flag);
	free(my_type);
	return (printed);
}

int	get_flags(const char *str, char *string, t_flag_values *flag)
{
	int		i;
	char	format;

	i = 0;
	(void)string;
	format = *str;
	while (*str && *str != '%')
		--str;
	get_flag_data(str, format, flag);
	get_width(str, format, flag);
	if (flag->width_nb < 0)
	{
		flag->width_nb = -flag->width_nb;
		flag->left_justify = true;
		flag->pad_zero = false;
	}
	if (string[1] == '0' && flag->precision_nb == 0)
		string[1] = '\0';
	return (1);
}

int	get_sign(char *string, char format, t_flag_values *flag)
{
	unsigned int	len;
	int				nb_prefix_chars;

	len = ft_count_len(string) - 1;
	nb_prefix_chars = count_digit_prefix(flag, format, string);
	flag->width_nb = flag->width_nb - get_biggest(len,
			flag->precision_nb) - nb_prefix_chars;
	if (flag->width_nb < 0)
		flag->width_nb = 0;
	if ((flag->left_justify && flag->width_nb != 0)
		|| (flag->pad_zero && flag->width_nb != 0
			&& flag->precision_nb <= -1))
	{
		disp_sign(format, flag, string);
		flag->sign_printed = true;
	}
	return (1);
}

int	print_number(char *string, t_flag_values *flag, int format)
{
	int		width_counter;
	char	pad;
	int		precision;
	int		printed;

	pad = ' ';
	precision = 0;
	width_counter = flag->width_nb;
	if (flag->pad_zero && flag->precision_nb <= -1)
		pad = '0';
	if (flag->precision_nb > (ft_count_len(string) - 1))
		precision = flag->precision_nb + 1 - ft_count_len(string);
	printed = precision + width_counter;
	if (!flag->left_justify)
		while (width_counter-- > 0)
			ft_putchar_fd(pad, 1);
	if (!flag->sign_printed)
		disp_sign(format, flag, string);
	while (precision-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr(string + 1);
	while (width_counter-- > 0)
		ft_putchar_fd(pad, 1);
	return (printed + flag->prefix_char_count + (ft_count_len(string + 1)));
}

int	print_digit(const char *str, t_type_holder *my_type, t_flag_values *flag)
{
	char	*string;
	char	*base;
	int		len;
	int		printed;

	base = base_creator(*str);
	len = ft_count_len(base);
	if (*str == 'd' || *str == 'i')
		string = ft_itoa_base(my_type->digit, base, len);
	else
		string = ft_u_itoa_base(my_type->ul_digit, base, len);
	if (!string || !base)
		return (error_malloc());
	get_flags(str, string, flag);
	len = ft_count_len(string) - 1;
	get_sign(string, *str, flag);
	printed = print_number(string, flag, *str);
	free(base);
	free(string);
	return (printed);
}
