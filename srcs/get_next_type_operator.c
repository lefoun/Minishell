/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_type_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:47:11 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/06 11:50:54 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_next_type_operator(int (*func_chercher[6])(char *str, int index, t_token **head), \
				char *arg, int index, t_token **head)
{
	int	i;

	i = 0;
	while (arg[i] && !is_operator(arg[i]))
		++i;
	while (!func_chercher[i](arg, index, head))
	{
		++i;
		if (i == 6)
			return (-1);
	}
	return (0);
}
