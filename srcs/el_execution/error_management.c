/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:46:37 by nammari           #+#    #+#             */
/*   Updated: 2021/12/07 14:07:47 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"


int	_here_doc_error_(void)
{
	ft_putstr_fd(variables->prog_name, 2);
	ft_putstr_fd(": warning: here_document delimited by EOF\n", 2);
	return (2);
}

int	_error_(char source)
{
	if (errno == 0)
		ft_putstr_fd("Error\n", 2);
	else if (source == 'o')
		perror("Error! Failed to open file");
	else if (source == 'p')
		perror("Error! Failed to open pipe");
	else if (source == 'k')
		perror("Error! Failed to fork");
	else if (source == 'd')
		perror("Error! Your dup2 failed");
	else if (source == 'c')
		perror("Error! Your Close failed");
	else if (source == 'a')
		ft_putstr_fd("Error ! Please enter command in this format: "
			"./pipex infile cmd1 cmd2 outfile\n", 2);
	else if (source == 'w')
		perror("Error! Your write failed");
	else
		ft_putstr_fd("Error!\n", 2);
	return (errno);
}

void	put_error(char *command)
{
	ft_putstr_fd(command, 2);
	ft_putstr_fd(" :command not found\n", 2);
}
