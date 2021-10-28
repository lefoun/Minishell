/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 22:20:05 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/14 16:44:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Gerer les retours des process ?
*/

int	create_processes(char **av, int pipefd[])
{
	char	**args;
	char	**path;
	int		pid;

	args = ft_split(av[2], ' ');
	path = get_paths(*args);
	pid = fork();
	if (pid == 0)
		return (cmd1(pipefd, av[1], args, path));
	free_tab(args);
	free_tab(path);
	args = ft_split(av[3], ' ');
	path = get_paths(*args);
	pid = fork();
	if (pid == 0)
		return (cmd2(pipefd, av[4], args, path));
	free_tab(args);
	free_tab(path);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}

int	main(int ac, char **av)
{
	int		pipefd[2];

	if (ac != 5)
	{
		printf("Error: Wrong number of args.\n");
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (2);
	}
	return (create_processes(av, pipefd));
}
