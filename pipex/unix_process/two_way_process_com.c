/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_way_process_com.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 00:02:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/28 00:55:07 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
// 5 => 5 * 4 = 20 => 20

int main()
{
	int p1[2]; // Child to parent
	int p2[2]; // Parent to child

	if (pipe(p1) == -1)
		return (-1);
	if (pipe(p2) == -1)
		return (-1);
	int pid = fork();
	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		close(p1[0]);
		close(p2[1]);
		int x;
		if (read(p2[0], &x, sizeof(x)) == -1)
			return (3);
		printf("Received %d\n", x);
		x = x * 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return (4);
		printf("Wrote %d\n",x);
		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		close(p1[1]);
		close(p2[0]);
		srand(time(NULL));
		int y = rand() % 10;
		if (write(p2[1], &y, sizeof(y)) == -1)
			return (5);
		printf("Wrote %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
			return (6);
		printf("Result is %d\n", y);
		close(p1[0]);
		close(p2[1]);
	}
	close(p1[0]);
	close(p2[1]);
	return (0);
}