/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/21 13:37:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//
// IMPORTANT: Change strcmp to ft_strcmp
//

void    delete_variable(t_environ *var)
{
    free(var->name);
    if (var->value != NULL)
        free(var->value);
    free(var);
}

int unset(t_environ **head, char *varname)
{
    t_environ   *env;
    t_environ   *prev;

    if (head == NULL)
        return (0);
    prev = NULL;
    env = *head;
    while (env != NULL)
    {
        if (strcmp(env->name, varname) == 0)
        {
            if (prev == NULL)
            {
                *head = env->next;
                delete_variable(env);
            }
            else
            {
                prev->next = env->next;
                delete_variable(env);
            }
            break ;
        }
        prev = env;
        env = env->next;
    }
    return (0);
}
