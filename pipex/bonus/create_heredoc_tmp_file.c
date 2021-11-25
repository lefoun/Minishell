/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc_tmp_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:27:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/14 19:58:22 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	continue_create_hd_tmp_file(t_heredoc_infile *hd_infile)
{
	hd_infile->fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, \
	S_IRUSR | S_IWUSR);
	if (hd_infile->fd < 0)
	{
		perror("open");
		return ;
	}
	write(hd_infile->fd, hd_infile->heredoc, ft_strlen(hd_infile->heredoc));
	close(hd_infile->fd);
	free(hd_infile->heredoc);
}

void	create_heredoc_tmp_file(char *limiter)
{
	t_heredoc_infile	hd_infile;

	hd_infile.heredoc = ft_strjoin("", "");
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		get_next_line(0, &hd_infile.line);
		if (ft_strlen(hd_infile.line) > ft_strlen(limiter))
			hd_infile.len = ft_strlen(hd_infile.line);
		else
			hd_infile.len = ft_strlen(limiter);
		if (ft_strncmp(hd_infile.line, limiter, hd_infile.len) == 0)
		{
			free(hd_infile.line);
			break ;
		}
		hd_infile.tmp = hd_infile.heredoc;
		hd_infile.heredoc = ft_strjoin(hd_infile.heredoc, hd_infile.line);
		free(hd_infile.line);
		free(hd_infile.tmp);
		hd_infile.tmp = hd_infile.heredoc;
		hd_infile.heredoc = ft_strjoin(hd_infile.heredoc, "\n");
		free(hd_infile.tmp);
	}
	continue_create_hd_tmp_file(&hd_infile);
}
