/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/22 18:10:51 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(void)
{
	char	*str;

	str = strerror(errno);
	printf("pwd: %s\n", str);
}

static bool	has_invalid_option(char *str)
{
	bool	has_hyphen;

	has_hyphen = false;
	if (str == NULL)
		return (false);
	while (*str == '-')
	{
		has_hyphen = true;
		str++;
	}
	if (*str != '\0' && has_hyphen == true)
		return (true);
	return (false);
}

int	ft_pwd(char **args)
{
	char	*working_directory;

	if (has_invalid_option(args[0]) == true)
	{
		write(2, "minishell: pwd: ", 16);
		write(2, args[0], ft_strlen(args[0]));
		write(2, ": invalid option\npwd: usage: pwd\n", 34);
		return (2);
	}
	working_directory = call_getcwd();
	if (working_directory == NULL)
	{
		print_error();
		return (1);
	}
	printf("%s\n", working_directory);
	free(working_directory);
	return (0);
}
