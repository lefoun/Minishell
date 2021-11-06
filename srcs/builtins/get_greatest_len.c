/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_greatest_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:55:40 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/06 18:57:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int get_greatest_len(char *str1, char *str2)
{
    unsigned int    len_str1;
    unsigned int    len_str2;

    len_str1 = ft_strlen(str1);
    len_str2 = ft_strlen(str2);
    if (len_str1 > len_str2)
        return (len_str1);
    return (len_str2);
}
