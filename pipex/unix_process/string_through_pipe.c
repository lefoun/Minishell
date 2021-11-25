/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:46:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/28 20:05:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main()
{
	int fd[2];
	if (pipe(fd) == -1)
		return 1;

	int pid = fork();
	if (pid < 0)
		return 2;
	
	if (pid == 0)
	{
		//Child process
		char str[200];
		printf("Input string: ");
		fgets(str, 200, stdin);
		
		int len = strlen(str) + 1;
		str[len - 1] = '\0';
		write(fd[1], &len, sizeof(int));
		write(fd[1], str, strlen(str) + 1);
	}
	else
	{
		// Parent process
		close(fd[1]);
		int len;
		char str[200];
		read(fd[0], &len, sizeof(int));
		read(fd[0], &str, len);
		printf("Received: %s", str);
		close(fd[0]);
		wait(NULL);
	}
	return 0;
}