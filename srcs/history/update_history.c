/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:03:41 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/04 16:47:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_history(char *cmd_line)
{
	if (cmd_line == NULL)
		return ;
	if (ft_strlen(cmd_line) == 0)
		return ;
	add_history(cmd_line);
}
