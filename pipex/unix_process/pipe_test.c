/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:21:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/27 23:35:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main()
{
	// fd[0] - read
	// fd[1] - write
	
	int fd[2];
	if (pipe(fd) == -1)
	{
		printf("An error occured with opening the pipe\n");
		return (1);
	}
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("An error occured with writing the pipe\n");
			return 2;
		}
		close(fd[1]);
	}
	else
	{
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("An error occured with reading the pipe\n");
			return 3;
		}
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}
	return (0);
}