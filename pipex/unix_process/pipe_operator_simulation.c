/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:57:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/28 21:33:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main()
{
	int fd[2];
	if (pipe(fd) == -1)
		return 2;

	int pid1 = fork();
	if (pid1 == -1)
		return 1;

	if (pid1 == 0)
	{
		// Child process
		char *args[] =
		{
			"ping",
			"-c",
			"5",
			"google.com",
			NULL
		};
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/ping", args, NULL);
	}

	int pid2 = fork();
	if (pid2 < 0)
		return 3;

	if (pid2 == 0)
	{
		// Child process 2 (grep)
		char *args2[] =
		{
			"grep",
			"rtt",
			NULL
		};
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/grep", args2, NULL);

	}
	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}