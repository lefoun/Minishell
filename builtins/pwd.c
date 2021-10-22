/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 16:51:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_error()
{
    char    *str;

    str = strerror(errno);
    printf("pwd: %s\n", str);
}

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
        if (len > MAX_PATH_LEN)
            break ;
    }
    print_error();
    return (1);
}
