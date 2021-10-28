/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:23:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/28 19:42:22 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

/*
** 2 processes
** 1 - Child process should generate random numbers and send them to the parent
** 2 - Parent is going to sum all the numbers and print the result
*/

int main()
{
	int fd[2];
	if (pipe(fd) == -1)
		return 2;
	int pid = fork();
	if (pid == -1)
		return 1;
	
	if (pid == 0)
	{
		// Child process
		close(fd[0]);
		int n, i;
		int arr[10];
		srand(time(NULL));
		n = rand() % 10 + 1;
		for (i = 0; i < n; i++)
		{
			arr[i] = rand() % 11;
			printf("[%d] ", arr[i]);
		}
		printf("\n");
		if (write(fd[1], &n, sizeof(int)) < 0)
			return 4;
		if (write(fd[1], arr, sizeof(int) * n) < 0)
			return 3;
		close(fd[1]);
	}
	else
	{
		// Parent process
		close(fd[1]);
		int arr[10];
		int n, i, sum = 0;
		read(fd[0], &n, sizeof(int));
		read(fd[0], arr, sizeof(int) * n);
		for (i = 0; i < n; i++)
		{
			sum = sum + arr[i];
			printf("|%d| ", arr[i]);
		}
		printf("\n");
		printf("Result is : %d\n", sum);
		wait(NULL);
		close(fd[0]);
	}
}