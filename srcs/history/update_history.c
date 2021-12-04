/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:03:41 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/04 12:20:19 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_history(void)
{
	if (ft_strlen(rl_line_buffer) == 0)
		return ;
	add_history(rl_line_buffer);
}
