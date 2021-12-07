/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/07 16:27:46 by nammari          ###   ########.fr       */
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
	if (str == NULL)
		return (false);
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

	if (variables->last_exit_status == 131)
		printf("Quit (core dumped)\n");
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

static void	edit_underscore_var(void)
{
	char	**args;
	char	*var;
	int		len;

	len = ft_strlen(variables->last_cmd_word);
	var = malloc(sizeof(char) * (len + 3));
	if (var == NULL)
		return ;
	args = malloc(sizeof(char *) * 2);
	if (args == NULL)
		return ;
	ft_strlcpy(var, "_=", 3);
	ft_strlcat(var, variables->last_cmd_word, len + 3);
	args[0] = var;
	args[1] = NULL;
	ft_export(args);
	free(args);
	free(var);
}

int	minishell(void)
{
	char	*cmd;
	while (true)
	{
		cmd = get_cmd_line();
		update_history(cmd);
		if (cmd == NULL)
		{
			free_ressources();
			exit(0);
		}
		ft_parser(cmd);
		edit_underscore_var();
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	struct sigaction	sa;

	(void)ac;
	shell_init(av, envp, &sa);
	minishell();
	return (0);
}
