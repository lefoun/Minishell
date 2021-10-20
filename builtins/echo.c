/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:40 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/20 17:22:37 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int echo(char *text, bool has_newline)
{
    ft_putstr(text);
    if (has_newline)
        write(1, "\n", 1);
    return (0);
}
