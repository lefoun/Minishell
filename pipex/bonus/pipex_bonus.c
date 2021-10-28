/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:52:43 by stone             #+#    #+#             */
/*   Updated: 2021/10/27 16:01:08 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_infile_outfile(t_pipex *pipex_datas, char *infile, char *outfile)
{
	pipex_datas->infilefd = open(infile, O_RDONLY);
	if (pipex_datas->infilefd < 0)
	{
		perror("open");
		return (3);
	}
	pipex_datas->outfilefd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex_datas->outfilefd < 0)
	{
		perror("open");
		return (3);
	}
	return (0);
}

int	call_cmd(t_pipex *pipex_datas, int ac)
{
	if (pipex_datas->process_nb == 1)
		return (cmd(pipex_datas->infilefd, pipex_datas->pipefd2[1], \
		pipex_datas->args, pipex_datas->path));
	else if (pipex_datas->process_nb == ac - 3)
		return (cmd(pipex_datas->pipefd1[0], pipex_datas->outfilefd, \
		pipex_datas->args, pipex_datas->path));
	return (cmd(pipex_datas->pipefd1[0], pipex_datas->pipefd2[1], \
	pipex_datas->args, pipex_datas->path));
}

int	handle_processes(t_pipex *pipex_datas, int ac, char **av)
{
	pipex_datas->process_nb = 1;
	while (pipex_datas->process_nb < ac - 2)
	{
		//
		pipe(pipex_datas->pipefd2);
		if (pipex_datas->pipefd2 < 0)
		{
			perror("pipe");
			return (1);
		}
		pipex_datas->args = ft_split(av[pipex_datas->process_nb + 1], ' ');
		pipex_datas->path = get_paths(*pipex_datas->args);
		pipex_datas->pid = fork();
		if (pipex_datas->pid < 0)
		{
			perror("fork");
			return (2);
		}
		if (pipex_datas->pid == 0)
			call_cmd(pipex_datas, ac);
		close(pipex_datas->pipefd1[0]);
		close(pipex_datas->pipefd2[1]);
		pipex_datas->pipefd1[0] = pipex_datas->pipefd2[0];
		pipex_datas->process_nb++;
	}
	return (0);
}

void	wait_processes(t_pipex *pipex_datas)
{
	while (pipex_datas->process_nb > 1)
	{
		wait(NULL);
		pipex_datas->process_nb--;
	}
}

int	main(int ac, char **av)
{
	t_pipex	pipex_datas;

	if (ac < 5)
	{
		printf("Error: Wrong number of args.\n");
		return (1);
	}
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		if (ac != 6)
		{
			printf("Error: Wrong numner of args(heredoc)\n");
			return (1);
		}
		heredoc(av[2], av[3], av[4], av[5]);
		return (0);
	}
	open_infile_outfile(&pipex_datas, av[1], av[ac - 1]);
	handle_processes(&pipex_datas, ac, av);
	close(pipex_datas.infilefd);
	close(pipex_datas.outfilefd);
	wait_processes(&pipex_datas);
	return (0);
}
