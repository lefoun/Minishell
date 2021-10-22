/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:27 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 17:31:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(char *path)
{
    char    *str;

    if (chdir(path) < 0)
    {
        str = strerror(errno);
        printf("cd: %s: %s\n", str, path);
        return (errno);
    }
    return (0);
}
