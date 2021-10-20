/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/20 17:58:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int pwd(void)
{
    unsigned int        i;
    unsigned int        len;
    char                *working_dir;

    i = 1;
    working_dir = NULL;
    while (true)
    {
        len = 42 * i;
        working_dir = malloc(len);
        if (getcwd(working_dir, len) != NULL)
        {
            printf("%s\n", working_dir);
            free(working_dir);
            return (0);
        }
        free(working_dir);
        i++;
        if ((unsigned long long)len > ULLONG_MAX)
            break ;
    }
    return (1);
}
