/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 23:40:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/28 00:00:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include  <sys/wait.h>

int main()
{
	int arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
	int arrSize = sizeof(arr) / sizeof(int);
	int start, end;
	
	int fd[2];
	if (pipe(fd) == -1)
		return 1;

	int id = fork();
	if (id == -1)
		return 2;
		
	if (id == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}

	int sum = 0;
	int i;
	for(i = start; i < end; i++)
	{
		sum = sum + arr[i];
	}
	printf("Calculated partial sum: %d\n", sum);

	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);

	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL);
	}

	return 0;
}