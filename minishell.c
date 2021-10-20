/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/20 18:55:52 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Add shell features into main function
** by merging git ranches
*/

t_environ	*create_env_var(char *name, char *value)
{
	t_environ	*new;

	new = malloc(sizeof(t_environ));
	if (new == NULL)
		return (NULL);
	new->name = name;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_env_var_back(t_environ **head, t_environ *new)
{
	t_environ	*env;

	if (*head == NULL)
		*head = new;
	else
	{
		env = *head;
		while (env->next != NULL)
			env = env->next;
		env->next = new;
	}
}

int	main(void)
{
	t_environ *env_vars = NULL;
	char name[] = "NEW_NAME";
	char value[] = "new_value";
	
	env(env_vars);
	add_env_var_back(&env_vars, create_env_var(name, value));
	add_env_var_back(&env_vars, create_env_var(name, value));

	env(env_vars);
	// char	*wd;
	// wd = malloc(26);
	// getcwd(wd, 26);
	// printf("cwd : |%s|\n", wd);
	pwd();
	cd("/Users/sdummett/minishell/builtins");
	pwd();
	printf("pepesh €\n");
	echo("hello world!", true);
	char name_[] = "MAIL";
	printf("env\n%s : |%s|\n", name_, getenv(name_));
	return (0);
}
