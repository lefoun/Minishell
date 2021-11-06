/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:06:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/06 19:07:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool    is_valid_identifier(char *str)
{
    unsigned int    i;

    i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] > 'A' && str[i] < 'Z') || \
            (str[i] > 'a' && str[i] < 'z') || str[i] == '_')
            i++;
        else
        {
            print_error(str);
            return (false);
        }
    }
    return (true);
}
