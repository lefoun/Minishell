#include "minishell.h"
#include <sys/wait.h>
#include <time.h>




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

char	*ft_strdup_index(char *str, int index)
{
	char	*duped_str;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	duped_str = malloc(sizeof(*duped_str) * index + 1);
	if (!duped_str)
		return (NULL);
	while (i < index)
	{
		duped_str[i] = str[i];
		++i;
	}
	return (duped_str);
}

bool	get_

bool	get_redirection_op(char *str, int index, t_token **head)
{
	t_token	*elem;
	int		i;
	int		j;

	if (*str != '>' && *str != '<')
		return (false);
	i = 0;
	j = 0;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]))
		++j;
	elem = malloc(sizeof(elem));
	if (!elem)
		return (false);
	if (*str == '<')
		elem->type = REDIR_IN;
	else
		elem->type = REDIR_OUT_TRUNC;
	elem->value = ft_strdup_index(str + i, j);
	if (!elem->value)
		return (false);
	ft_pushback(head, elem);
	return (true);
}

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

int main(void)
{

    // int type = 0;
    // if (type == OPERATOR)
    //     printf("bidule\n");
    // else
    //     printf("Not bidule\n");
    return (0);
}
