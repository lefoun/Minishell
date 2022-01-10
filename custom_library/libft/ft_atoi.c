/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <nammari@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:18:53 by noufel            #+#    #+#             */
/*   Updated: 2021/03/28 17:16:34 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	overflow_check(const char *str, int sign)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	if (i >= 20 && sign == -1)
		return (0);
	else if (i >= 20 && sign == 1)
		return (-1);
	return (2);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
		sign = -sign;
	if (*str == '-' || *str == '+')
		++str;
	else if (*str == '+')
		++str;
	if (overflow_check(str, sign) < 2)
		return (overflow_check(str, sign));
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		++str;
	}
	return (result * sign);
}
