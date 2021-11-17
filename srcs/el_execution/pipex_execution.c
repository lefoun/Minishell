/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:03:46 by nammari           #+#    #+#             */
/*   Updated: 2021/11/17 16:09:02 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ----- Pipex utils -----------

int	mem_free(char **tab, int index, t_command_vars *commands)
{
	while (tab && tab[index])
	{
		free(tab[index]);
		++index;
	}
	if (tab)
		free(tab);
	tab = NULL;
	if (commands->input_fd != -1)
	{
		close(commands->input_fd);
		commands->input_fd = -1;
	}
	if (commands->output_fd != -1)
	{
		close(commands->output_fd);
		commands->output_fd = -1;
	}
	return (-1);
}

void	double_free(char *tab, char *tab2)
{
	free(tab);
	free(tab2);
}


int	_error_(char source)
{
	if (source == 'o')
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
	return (-1);
}

void	put_error(char *command)
{
	ft_putstr_fd(command, 2);
	ft_putstr_fd(" :command not found\n", 2);
}

int	close_pipes(int fd_1, int fd_2)
{
	close(fd_1);
	close(fd_2);
	return (0);
}


//------ Parsing for pipex ---------
char	*search_path(char *string)
{
	if (!string)
		return (NULL);
	if (!(string[0] && string[0] == 'P'))
		return (NULL);
	if (!(string[1] && string[1] == 'A'))
		return (NULL);
	if (!(string[2] && string[2] == 'T'))
		return (NULL);
	if (!(string[3] && string[3] == 'H'))
		return (NULL);
	return (string);
}

char	**get_paths(char *env[])
{
	char			**paths;
	char			*tmp;
	int				i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i] && search_path(env[i]) == NULL)
		++i;
	if (!env[i])
		return (NULL);
	paths = ft_split(ft_strchr(env[i], '/'), ':');
	i = 0;
	while (paths && paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		++i;
	}
	return (paths);
}

char	*get_here_doc_content(int fd, char *limiter, char **str)
{
	char	*tmp;
	char	*tab;

	tmp = NULL;
	tab = NULL;
	*str = ft_strdup("");
	while (get_next_line(fd, &tab) > 0)
	{
		tmp = *str;
		if (!tab)
			break ;
		if (ft_memcmp(tab, limiter, ft_strlen(tab)) == 0)
		{
			free(tab);
			get_next_line(fd, &tab);
			return (*str);
		}
		*str = ft_strjoin(tmp, tab);
		free(tmp);
		tmp = *str;
		*str = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	double_free(*str, tab);
	return (NULL);
}

int	init_here_doc(char *limiter)
{
	int		here_doc;
	char	*file_content;

	file_content = NULL;
	file_content = get_here_doc_content(0, limiter, &file_content);
	if (!file_content)
		return (-1);
	here_doc = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (here_doc == -1)
	{
		free(file_content);
		return (_error_('o'));
	}
	if (write(here_doc, file_content, ft_strlen(file_content)) == -1)
	{
		free(file_content);
		return (_error_('w'));
	}
	close(here_doc);
	here_doc = open("here_doc", O_RDWR);
	free(file_content);
	return (here_doc);
}

int	init_command_fds(t_command_vars *commands, char **argv, int argc)
{
	if (ft_strlen(argv[1]) >= 8 && ft_strnstr(argv[1], "here_doc", 8))
	{
		if (argc < 6)
			return (_error_('a'));
		commands->input_fd = init_here_doc(argv[2]);
		if (commands->input_fd < 0)
			return (_error_('b'));
		commands->here_doc = true;
		commands->output_fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT,
				0666);
		if (commands->output_fd == -1)
			return (_error_('o'));
		commands->name++;
	}
	else
	{
		commands->input_fd = open(argv[1], O_RDONLY | O_NONBLOCK);
		if (commands->input_fd == -1)
			_error_('o');
		commands->output_fd = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT,
				0666);
		if (commands->output_fd == -1)
			_error_('o');
	}
	return (1);
}
/// ------ End of parsing for pipex ----------

int	exec_command(char **my_paths, char **argv, t_command_vars *commands)
{
	char	*path;
	char	**args;

	// int i = -1;
	// while (argv[++i])
	// 	dprintf(2, "This is argv[%d]: |%s|\n", i, argv[i]);
	args = ft_split(*(argv), ' ');
	if (!args)
		return (-1);
	execve(args[0], argv, commands->env);
	path = ft_strjoin("./", *args);
	if (!path)
		return (-1);
	while (execve(path, argv, commands->env) == -1)
	{
		free(path);
		if (!my_paths)
			return (mem_free(args, 0, commands));
		path = ft_strjoin(*my_paths, *args);
		if (!path)
			return (mem_free(args, 0, commands));
		++my_paths;
	}
	free(path);
	return (mem_free(args, 0, commands));
}

int	apply_redirection(int in, int out, t_token **head)
{
	int	fd;

	if (*head == NULL || (*head)->next == NULL)
		return (1);
	if ((*head)->next->type == REDIR_IN)
	{
		dprintf(2, "here\n");
		fd = open((*head)->next->value, O_RDONLY);
		dup2(in, fd);
		close(in);
	}
	else if ((*head)->next->type == REDIR_OUT_APPEND || (*head)->next->type == REDIR_OUT_TRUNC)
	{
		dprintf(2, "here2\n");
		fd = open((*head)->next->value, O_RDWR);
		dup2(fd, out);
		//close(out);
		dprintf(2, "This is out %d and fd %d\n", out, fd);
	}
	dprintf(2, "here3\n");
	return (0);
}

int	ft_fork(t_command_vars *commands, int in, int out, int pipe_fds[2], t_token **head)
{
	int	pid;
	
	pid = fork();
	if (pid == -1)
		return (_error_('k'));
	if (pid == 0)
	{
		if (commands->is_first_command == true)
			close(pipe_fds[0]);
		dup2(in, STDIN_FILENO);
		// if (close(in) == -1)
		// 	exit(EXIT_FAILURE);
		dup2(out, STDOUT_FILENO);
		// if (out != -1)
		// 	close(out);
		apply_redirection(in, out, head);
		if (exec_command(commands->paths, (*head)->cmd, commands) == -1)
		{
			write(1, "here error\n", 11);
			put_error(commands->name[0]);
			close(pipe_fds[0]);
			close_pipes(0, 1);
			mem_free(commands->paths, 0, commands);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

int	call_fork(t_command_vars *com, int pipe_fds[2], int index, int prev_output, t_token **head)
{
	int	ret;

	com->is_first_command = false;
	if (index == 0)
	{
		com->is_first_command = true;
		ret = ft_fork(com, com->input_fd, pipe_fds[1], pipe_fds, head);
	}
	else if (index + 1 == com->nb)
	{
		ret = ft_fork(com, prev_output, com->output_fd, pipe_fds, head);
	}
	else
	{
		ret = ft_fork(com, prev_output, pipe_fds[1], pipe_fds, head);
	}
	if (ret == 1)
	{
		close_pipes(pipe_fds[1], pipe_fds[0]);
		return (-1);
	}
	return (1);
}


int	pipex(t_command_vars *commands, t_token **head)
{
	int		pipe_fds[2];
	int		prev_output;
	int		ret;
	int		i;

	i = -1;
	while (++i < commands->nb)
	{
		if (i + 1 < commands->nb)
			if (pipe(pipe_fds) == -1)
				return (_error_('p'));
		ret = call_fork(commands, pipe_fds, i, prev_output, head);
        *head = (*head)->next;
        if (*head != NULL && (*head)->type == PIPE)
            *head = (*head)->next;
		close(pipe_fds[1]);
		if (i != 0)
			close(prev_output);
		if (ret != -1)
			prev_output = pipe_fds[0];
	}
	i = -1;
	while (++i < commands->nb)
		wait(NULL);
	return (0);
}

int	pipex_exec_test(int nb_args, t_token **head, char **environ)
{
	t_command_vars	commands;

	commands.paths = get_paths(environ);
	commands.here_doc = false;
	commands.name = (*head)->cmd;
    commands.input_fd = 0;
    commands.output_fd = 1;
	commands.env = environ;
	commands.nb = nb_args;
	pipex(&commands, head);
	return (0);
}