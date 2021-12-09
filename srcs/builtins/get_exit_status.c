/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:48:26 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/09 11:05:35 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (false);
	return (true);
}

static unsigned long	ato_exit_status(char *str, int sign,
	bool *arg_is_numeric)
{
	unsigned long	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		if (sign == 1 && nb > (unsigned long)LLONG_MAX)
		{
			*arg_is_numeric = false;
			break ;
		}
		if (sign == -1 && nb > (unsigned long)LLONG_MAX + 1)
		{
			*arg_is_numeric = false;
			break ;
		}
		str++;
	}
	return (nb);
}

int	get_exit_status(char *str, bool *arg_is_numeric)
{
	int				sign;
	unsigned long	exit_status;

	*arg_is_numeric = is_number(str);
	if (arg_is_numeric == false)
		return (2);
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	exit_status = ato_exit_status(str, sign, arg_is_numeric);
	if (arg_is_numeric == false)
		return (2);
	return ((int)exit_status * sign);
}
