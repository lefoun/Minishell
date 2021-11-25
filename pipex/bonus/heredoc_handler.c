/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:47:42 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/14 20:08:37 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	heredoc_parse_args(t_heredoc *heredoc_datas, char *cmd1, char *cmd2)
{
	heredoc_datas->args1 = ft_split(cmd1, ' ');
	heredoc_datas->path1 = get_paths(*heredoc_datas->args1);
	heredoc_datas->args2 = ft_split(cmd2, ' ');
	heredoc_datas->path2 = get_paths(*heredoc_datas->args2);
}

void	close_heredoc_fds(t_heredoc *heredoc_datas)
{
	close(heredoc_datas->pipefd[0]);
	close(heredoc_datas->pipefd[1]);
	close(heredoc_datas->fd_heredoc);
	close(heredoc_datas->fd_out);
	wait(NULL);
	unlink(".heredoc");
}

void	heredoc_create_process(t_heredoc *heredoc_datas, char *cmd1, char *cmd2)
{
	heredoc_parse_args(heredoc_datas, cmd1, cmd2);
	heredoc_datas->pid = fork();
	if (heredoc_datas->pid < 0)
	{
		perror("fork");
		return ;
	}
	if (heredoc_datas->pid == 0)
	{
		if (heredoc_datas->process_nb == 0)
		{
			cmd(heredoc_datas->fd_heredoc, heredoc_datas->pipefd[1], \
			heredoc_datas->args1, heredoc_datas->path1);
			exit(1);
		}
		else
		{
			cmd(heredoc_datas->pipefd[0], heredoc_datas->fd_out, \
			heredoc_datas->args2, heredoc_datas->path2);
			exit(1);
		}
	}
}

void	continue_heredoc(t_heredoc *heredoc_datas, char *cmd1, char *cmd2)
{
	heredoc_datas->process_nb = 0;
	while (heredoc_datas->process_nb < 2)
	{
		heredoc_create_process(heredoc_datas, cmd1, cmd2);
		heredoc_datas->process_nb++;
	}
}

void	heredoc(char *limiter, char *cmd1, char *cmd2, char *outfile)
{
	t_heredoc	heredoc_datas;

	create_heredoc_tmp_file(limiter);
	heredoc_datas.fd_heredoc = open(".heredoc", O_RDONLY);
	if (heredoc_datas.fd_heredoc < 0)
	{
		perror("open");
		return ;
	}
	heredoc_datas.fd_out = open(outfile, O_CREAT | O_WRONLY | O_APPEND, \
	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (heredoc_datas.fd_out < 0)
	{
		perror("open");
		return ;
	}
	pipe(heredoc_datas.pipefd);
	if (heredoc_datas.pipefd < 0)
	{
		perror("pipe");
		return ;
	}
	continue_heredoc(&heredoc_datas, cmd1, cmd2);
	close_heredoc_fds(&heredoc_datas);
}
