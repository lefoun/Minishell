/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/04 10:58:35 by sdummett         ###   ########.fr       */
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

static int	get_exit_status(char *str, bool *arg_is_numeric)
{
	int				sign;
	unsigned long	exit_status;

	*arg_is_numeric = is_number(str);
	if (arg_is_numeric == false)
		return (2);
	sign = 1;
	exit_status = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		exit_status = (exit_status * 10) + (*str - '0');
		if (sign == 1 && exit_status > (unsigned long)LLONG_MAX)
		{
			*arg_is_numeric = false;
			return (2);
		}
		if (sign == -1 && exit_status > (unsigned long)LLONG_MAX + 1)
		{
			*arg_is_numeric = false;
			return (2);
		}
		str++;
	}
	return ((int)exit_status * sign);
}

int	ft_exit(char **args)
{
	int		exit_status;
	bool	arg_is_numeric;

	write(2, "exit\n", ft_strlen("exit\n"));
	if (args == NULL)
	{
		// FREE ALL THE RESSOURCES !
		exit(variables->last_exit_status);
	}
	arg_is_numeric = true;
	exit_status = get_exit_status(args[0], &arg_is_numeric);
	if (arg_is_numeric == true && args[1] != NULL)
	{
		write(2, variables->prog_name, ft_strlen(variables->prog_name));
		write(2, ": exit: too many arguments\n",
			ft_strlen(": exit: too many arguments\n"));
		return (1);
	}
	if (arg_is_numeric == false)
	{
		write(2, variables->prog_name, ft_strlen(variables->prog_name));
		write(2, ": exit: ", ft_strlen(": exit: "));
		write(2, args[0], ft_strlen (args[0]));
		write(2, ": numeric argument required\n",
			ft_strlen(": numeric argument required\n"));
	}
	// FREE ALL THE RESSOURCES !
	exit(exit_status);
}
