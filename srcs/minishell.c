/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/04 10:36:22 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars	*variables = NULL;

static bool	pipe_is_unclosed(char *str)
{
	unsigned int	i;
	char			c;

	i = 0;
	c = '\0';
	while (str[i] != '\0')
	{
		while (is_whitespace(str[i]))
			i++;
		if (str[i] != '\0')
		{
			c = str[i];
			i++;
		}
	}
	if (c == '|')
		return (true);
	return (false);
}

static char	*get_cmd_line(void)
{
	char	*cmd_line;
	char	*tmp;
	char	*new_line;

	cmd_line = readline(BGRN"[pepesh €] "RESET);
	while (pipe_is_unclosed(cmd_line))
	{
		tmp = cmd_line;
		new_line = readline("> ");
		cmd_line = malloc(sizeof(char) * (ft_strlen(tmp)
					+ ft_strlen(cmd_line) + 1));
		if (new_line == NULL)
			return (NULL);
		ft_strlcpy(cmd_line, tmp, ft_strlen(tmp) + 1);
		ft_strlcat(cmd_line, new_line, ft_strlen(new_line)
			+ ft_strlen(tmp) + 1);
		free(tmp);
		free(new_line);
		rl_replace_line(cmd_line, 0);
	}
	return (cmd_line);
}

int	main(int ac, char **av, char **envp)
{
	char	*cmd;

	(void)ac;
	shell_init(av, envp);
	get_environment();
	while (true)
	{
		cmd = get_cmd_line();
		update_history();
		ft_parser(cmd);
		free(cmd);
	}	
	return (0);
}
