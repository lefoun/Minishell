/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/09 10:50:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	too_many_args_msg(void)
{
	write(2, g_variables->prog_name, ft_strlen(g_variables->prog_name));
	write(2, ": exit: too many arguments\n",
		ft_strlen(": exit: too many arguments\n"));
}

static void	num_args_req_msg(char *str)
{
	write(2, g_variables->prog_name, ft_strlen(g_variables->prog_name));
	write(2, ": exit: ", ft_strlen(": exit: "));
	write(2, str, ft_strlen (str));
	write(2, ": numeric argument required\n",
		ft_strlen(": numeric argument required\n"));
}

int	ft_exit(char **args)
{
	int		exit_status;
	bool	arg_is_numeric;

	write(2, "exit\n", ft_strlen("exit\n"));
	if (args[0] == NULL)
	{
		exit_status = g_variables->last_exit_status;
		free_ressources();
		exit(exit_status);
	}
	arg_is_numeric = true;
	exit_status = get_exit_status(args[0], &arg_is_numeric);
	if (arg_is_numeric == true && args[1] != NULL)
	{
		too_many_args_msg();
		return (1);
	}
	if (arg_is_numeric == false)
		num_args_req_msg(args[0]);
	free_ressources();
	exit(exit_status);
}
