/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/30 21:52:15 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//
// IMPORTANT: Change strcmp to ft_strcmp
//

static void    print_error(char *str)
{
    write(2, "pepesh: unset: `", 16);
    write(2, str, ft_strlen(str));
    write(2, "': not a valid identifier\n", 26);
}
static bool    is_valid_identifier(char *str)
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

static unsigned int get_greatest_len(char *str1, char *str2)
{
    unsigned int    len_str1;
    unsigned int    len_str2;

    len_str1 = ft_strlen(str1);
    len_str2 = ft_strlen(str2);
    if (len_str1 > len_str2)
        return (len_str1);
    return (len_str2);
}

static void    delete_variable(t_variable **head, char *varname_to_del)
{
    unsigned int    len;
    t_variable      *env;
    t_variable      *previous;

    env = *head;
    previous = NULL;
    while (env != NULL)
    {
        len = get_greatest_len(env->name, varname_to_del);
        if (ft_strncmp(env->name, varname_to_del, len) == 0)
        {
            if (previous == NULL)
                *head = env->next;
            else
                previous->next = env->next;
            free(env->name);
            free(env->value);
            free(env);
            return ;
        }
        previous = env;
        env = env->next;
    }
}

int ft_unset(char **args)
{
    bool            all_unset;
    unsigned int    i;

    i = 0;
    all_unset = true;
    while (args[i] != NULL)
    {
        if (is_valid_identifier(args[i]))
            delete_variable(&variables->env, args[i]);
        else
            all_unset = false;
        i++;
    }
    if (all_unset == false)
        return (1);
    return (0);
}
