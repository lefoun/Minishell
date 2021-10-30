/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/30 19:33:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void    print_error()
{
    char    *str;

    str = strerror(errno);
    printf("pwd: %s\n", str);
}

int ft_pwd(char **args)
{
    char                *working_directory;

    (void)args;
    working_directory = call_getcwd();
    if (working_directory == NULL)
    {
        print_error();  
        return (1);
    }
    printf("%s\n", working_directory);
    free(working_directory);
    return (0);
}
