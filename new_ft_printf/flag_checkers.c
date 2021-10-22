/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:14:52 by nammari           #+#    #+#             */
/*   Updated: 2021/07/06 20:07:05 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 		5 / 5 functions

bool	is_width_flag(const char *str, int *index)
{
	int	i;

	i = 0;
	if (str[*index] == '*' && ft_isdigit(str[*index + 1]))
		return (false);
	if (ft_isdigit(str[*index]) && str[*index + 1] == '*')
		return (false);
	if (str[*index] == '*')
	{
		++(*index);
		return (true);
	}
	if (ft_isdigit(str[*index]))
	{
		while (str[*index] && ft_isdigit(str[*index]))
			++(*index);
		return (true);
	}
	return (false);
}

bool	is_precision_flag(const char *str, int *index)
{
	if (str[*index] == '.')
	{
		++(*index);
		if (str[*index] == '*')
		{
			++(*index);
			return (true);
		}
		while (ft_isdigit(str[*index]))
			++(*index);
		return (true);
	}
	return (false);
}

bool	is_primary_flag(char c)
{
	if (c == '-' || c == '0' || c == '.'
		|| c == '*' || c == '+' || c == ' ' || c == '#')
		return (true);
	return (false);
}

//Function below to be deleted before pushing
bool	wildcard_width_checker(const char	*str)
{
	while (*str && *str != '%')
		--str;
	++str;
	while (*str && !is_specifier(*str) && *str != '.' && *str != '%')
	{
		if (*str == '*')
		{
			return (true);
		}
		++str;
	}
	return (false);
}

bool	wildcard_precision_checker(const char	*str)
{
	while (*str && *str != '%')
	{
		--str;
		if (*str == '.' && (*(str + 1) == '*'))
		{
			return (true);
		}
	}
	return (false);
}
