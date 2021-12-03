/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:10:15 by nammari           #+#    #+#             */
/*   Updated: 2021/12/03 21:31:20 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_function_pointer(int (*get_redirection[])
					(char **, int *, t_token **))
{
	get_redirection[0] = get_redir_out_append;
	get_redirection[1] = get_redir_out_trunc;
	get_redirection[2] = get_redir_input_here_doc;
	get_redirection[3] = get_redir_input_file;
}
