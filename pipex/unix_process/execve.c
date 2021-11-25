/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 01:02:32 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/28 18:59:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
** open includes
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** Executing a command using execve
*/

int main()
{
	int pid = fork();
	char *args[] =
		{
			"ping",
			"-c",
			"3",
			"google.com",
			NULL};
	if (pid == -1)
		return 1;

	int fd = open("pingResults", O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		return 2;
	if (pid == 0)
	{
		printf("The fd to pingResults : %d\n", fd);
		int fd2 = dup2(fd, STDOUT_FILENO);
		printf("The duplicated fd : %d\n", fd2);
		close(fd);

		if (execve("/usr/bin/ping", args, NULL))
			perror("execve");
		printf("THIS NOT PRINT ON THEN TERMINAL!\n");
	}
	else
	{
		int wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("Success !\n");
			else
				printf("Failure with status code %d!\n", statusCode);
		}
		printf("Some post processing goes here\n");
	}
	return (0);
}

/*
** Executing a command using exclp
*/

/*
int main()
{
	int pid = fork();
	if (pid == -1)
		return 1;
		
	if (pid == 0)
	{
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
		printf("THIS NOT PRINT ON THEN TERMINAL!\n");
	}
	else
	{
		wait(NULL);
		printf("Succes !\n");
		printf("Some post processing goes here\n");
	}
	
	return (0);
}
*/