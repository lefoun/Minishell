/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:19:27 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/11 16:45:11 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ft_create_ast
*/

t_ast	*ft_create_ast(char *cmd_line)
{
	int	i;

	i = 0;
	while (cmd_line[i])
	{
		ft_parser(cmd_line);
		break ;
	}
	// un moyen de savoir où est-ce que le mot 
	// une fontion qui va chercher le type word, etc.
	// une fonction qui va créer le maillon en assignant le type et la valeur
	// repeat jusqu'à ce qu'il y ait plus de arg[x];
	return (NULL);
}
