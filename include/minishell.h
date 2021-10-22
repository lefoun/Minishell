/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/10/22 17:31:27 by sdummett         ###   ########.fr       */
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
# include "colorcodes.h" 
// # include "ft_printf.h" <- Add the library

# define MAX_FILE_NAME_LEN 255
# define MAX_PATH_LEN 4096
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
}	t_vars;

void		add_variable(t_variable **head, t_variable *new);
t_variable	*create_variable(char *name, char *value);
/*
** Builtins utils
*/
char	**get_variables_assignations(char **args);

/*
** Builtins
*/
int			ft_cd(char *path);
int			ft_echo(char *text, bool has_newline);
int			ft_pwd(void);
int			ft_export(t_variable **env,char *name, char *value);
int			ft_unset(t_variable **head, char *varname);
int			ft_env(t_variable *env);
void		ft_exit(int exit_status);

/*
** Environment functions
*/
t_variable	*create_env_var(char *name, char *value);
void		add_env_var_back(t_variable **head, t_variable *new);

/*
** Temporary
*/
int			ft_strlen(const char *str); //<- delete ft_strlen.c
void		ft_putstr(char *str); //<-delete ft_putstr.c
char		*ft_strdup(const char *str); //<-delete ft_strdup.c
void		printenv(t_variable *env); //<-delete printenv.c

#endif
