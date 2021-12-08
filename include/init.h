/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:25:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/08 21:49:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

/*
** Environment structure
*/
typedef struct s_variable
{
	char				*name;
	char				*value;
	struct s_variable	*next;
}	t_variable;

/*
** Variables
*/
typedef struct s_vars
{
	t_variable	*env;
	t_variable	*global;
	int			last_exit_status;
	char		*prog_name;
	char		*last_cmd_word;
}	t_vars;

/* 
** Environment variables is a global linked list
*/
extern t_vars	*g_variables;

int				shell_init(char **av, char **envp, struct sigaction *sa);
t_vars			*init_env(char **av);

#endif