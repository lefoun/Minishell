/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_type_operator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:47:11 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/07 11:33:28 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_next_type_operator(int (*get_operators[6])(char *str, t_token **head), \
				char *arg, t_token **head)
{
	int	i;

	i = 0;
	while (arg[i] && !is_operator(arg[i]))
		++i;
	while (!get_operators[i](arg, head))
	{
		++i;
		if (i == 6)
			return (-1);
	}
	return (0);
}
