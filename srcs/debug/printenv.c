/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:43:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 17:34:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printenv(t_variable *environ)
{
	printf( BMAG "==> ENVIRONMENT <==\n" RESET);
	printf( GRN "");
	ft_env(environ);
	printf( RESET "");
}