/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:43:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/21 13:50:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printenv(t_environ *environ)
{
	printf( BMAG "==> ENVIRONMENT <==\n" RESET);
	printf( GRN "");
	env(environ);
	printf( RESET "");
}