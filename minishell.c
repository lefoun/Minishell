/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/30 01:20:28 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*ft_create_ast(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		
	}
	// un moyen de savoir où est-ce que le mot 
	// une fontion qui va chercher le type word, etc.
	// une fonction qui va créer le maillon en assignant le type et la valeur
	// repeat jusqu'à ce qu'il y ait plus de arg[x];

}

t_token *ft_tokenize(char *arg)
{
	t_token	*head;
	char	**splited_arguments;
	int		i;

	i = 0;
	while (arg[i])
	{

		i = get_bidule();
		get_op_elem();
		while (!is_space(*arg))
			++j;
	}
}

/*
** Create boolean function for function pointer
** bool	get_
*/

int	get_bidule(bool (*func_chercher[6])(char *str, int index, t_token **head),
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
}

int	get_index_of_operator(char *arg)
{
	int	i;

	i = 0;
	return (i);
}

t_token	*ft_create_element(t_token **head, char *arg, int index)
{

}

bool	is_operator(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '&')
		return (true);
	return (false);
	// if (*str == '&' && *(str + 1) != '&')
	// 	return (false);
	// else
	// 	return (true);
}

int	ft_parser(char *arg)
{
	t_ast	*root;
	t_token *head;

	head = ft_tokenize(arg);
	root = ft_create_ast(arg);
	if (!root)
		return (-1);
}

int	main(void)
{
	
	return (0);
}