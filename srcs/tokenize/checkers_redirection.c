/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:35:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/03 21:36:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redirection_input(char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	if (*str == '<')
		return (true);
	return (false);
}

bool	is_redirection_output_trunc(char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	if (*str == '>')
		return (true);
	return (false);
}

bool	is_redirection_output_append(char *str)
{
	if (str == NULL || str[0] == '\0' || str[1] == '\0')
		return (false);
	if (str[0] == '>' && str[1] == '>')
		return (true);
	return (false);
}

bool	is_redirection_input_here_doc(char *str)
{
	if (str == NULL || str[0] == '\0' || str[1] == '\0')
		return (false);
	if (str[0] == '<' && str[1] == '<')
		return (true);
	return (false);
}
