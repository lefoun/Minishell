/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:56:16 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/28 23:07:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main()
{
	int pid1 = fork();
	if (pid1 == -1)
	{
		printf("Error creating process\n");
		return 1;
	}
	if (pid1 == 0)
	{
		sleep(4);
		printf("Finished execution (%d)\n", getpid());
		return 0;
	}

	int pid2 = fork();
	if (pid2 == -1)
	{
		printf("Error creating process\n");
		return 2;
	}

	if (pid2 == 0)
	{
		sleep(1);
		printf("Finished execution (%d)\n", getpid());
		return 0;
	}
	
	int pid1_res = waitpid(-1, NULL, WNOHANG);
	printf("Waited for %d\n", pid1_res);
	int pid2_res = waitpid(pid2, NULL, WNOHANG);
	printf("Waited for %d\n", pid2_res);
	return 0;
}