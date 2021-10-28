/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/28 17:04:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void    print_error()
{
    char    *str;

    str = strerror(errno);
    printf("pwd: %s\n", str);
}

int ft_pwd(void)
{
    char                *working_directory;

    working_directory = call_getcwd();
    if (working_directory != NULL)
    {
        printf("%s\n", working_directory);
        free(working_directory);
        return (0);
    }
    else
        print_error();
    return (1);
}
