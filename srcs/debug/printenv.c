/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:43:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/22 18:37:00 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printenv(void)
{
	printf(BMAG "==> ENVIRONMENT <==\n" RESET);
	printf(GRN "");
	ft_env(NULL);
	printf(RESET "");
}
