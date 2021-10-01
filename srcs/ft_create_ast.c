/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:19:27 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/30 21:06:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ft_create_ast
*/

t_ast	*ft_create_ast(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		ft_parser(arg);
		break ;
	}
	// un moyen de savoir où est-ce que le mot 
	// une fontion qui va chercher le type word, etc.
	// une fonction qui va créer le maillon en assignant le type et la valeur
	// repeat jusqu'à ce qu'il y ait plus de arg[x];
	return (NULL);
}
