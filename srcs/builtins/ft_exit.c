/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/02 13:34:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exit(char **args)
{
    long long   exit_status;

    (void)args;
    if (args == NULL)
        exit(variables->last_exit_status);
    exit_status = 42;
    exit((int)exit_status);
}
