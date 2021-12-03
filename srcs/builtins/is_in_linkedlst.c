/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_linkedlst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:36:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/03 14:40:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_in_linkedlst(void *ptr)
{
	while (variables->environ)
	{
		if (ptr == variables->environ->content)
			return (true);
		variables->environ = variables->environ->next;
	}
	return (false);
}