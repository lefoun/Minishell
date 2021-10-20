/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/10/21 00:19:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <time.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
// # include "ft_printf.h" <- Add the library

/*
** Environment structure
*/
typedef struct s_environ
{
	char				*name;
	char				*value;
	struct s_environ	*next;
}	t_environ;

/*
** Builtins
*/
int			cd(char *path);
int			echo(char *text, bool has_newline);
int			pwd(void);
int			export_(t_environ **t_environ,char *name, char *value);
int			unset(t_environ **head, char *varname);
int			env(t_environ *env_vars);
void		exit_(int exit_status);

/*
** Environment functions
*/
t_environ	*create_env_var(char *name, char *value);
void		add_env_var_back(t_environ **head, t_environ *new);

/*
** Temporary
*/
int			ft_strlen(const char *str); //<- delete ft_strlen.c
void		ft_putstr(char *str); //<-delete ft_putstr.c
char		*ft_strdup(const char *str); //<-delete ft_strdup.c

#endif
