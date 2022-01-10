/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:10:56 by nammari           #+#    #+#             */
/*   Updated: 2021/07/07 23:52:47 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//      5 / 5 functions

char	*ft_u_itoa_base(unsigned long num, char *to_base, int base_len)
{
	char	*string;
	int		len;

	if (!to_base)
		return (NULL);
	len = count_unum_len(num, base_len);
	string = malloc(sizeof(*string) * (len + 2));
	if (!string)
		return (NULL);
	string[0] = '+';
	string[len + 1] = '\0';
	while (len > 0)
	{
		if ((num % base_len) <= 9)
			string[len--] = (num % base_len) + '0';
		else
			string[len--] = to_base[num % base_len];
		num = num / base_len;
	}
	return (string);
}

char	*ft_itoa_base(long num, char *to_base, int base_len)
{
	char	*string;
	int		len;

	if (!to_base)
		return (NULL);
	len = count_num_len(num, base_len);
	string = malloc(sizeof(*string) * (len + 2));
	if (!string)
		return (NULL);
	string[0] = '+';
	if (num < 0)
		string[0] = '-';
	if (num < 0)
		num = -num;
	string[len + 1] = '\0';
	while (len > 0)
	{
		if ((num % base_len) <= 9)
			string[len--] = to_base[num % base_len];
		else
			string[len--] = to_base[num % base_len];
		num = num / base_len;
	}
	return (string);
}

int	count_unum_len(unsigned long long num, int base_len)
{
	int					i;
	unsigned long long	len;

	i = 0;
	len = base_len;
	if (num < len)
		return (1);
	while (num)
	{
		num = num / len;
		++i;
	}
	return (i);
}

int	count_num_len(long long num, int base_len)
{
	int			i;
	long long	len;

	len = base_len;
	i = 0;
	if (num < 0)
		num = -num;
	if (num < len)
		return (1);
	while (num)
	{
		num = num / len;
		++i;
	}
	return (i);
}

char	*base_creator(char format)
{
	int		i;
	int		len;
	char	*base;
	char	c;

	i = -1;
	c = '0';
	len = 0;
	if (format == 'x' || format == 'X' || format == 'p')
		len = 16;
	else
		len = 10;
	base = malloc(sizeof(char) * (len + 1));
	if (!base)
		return (NULL);
	while (++i < 10 && i < len)
		base[i] = c++;
	if (format == 'x' || format == 'p')
		c = 'a';
	else if (format == 'X')
		c = 'A';
	while (i < len)
		base[i++] = c++;
	base[len] = '\0';
	return (base);
}
