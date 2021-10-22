/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/10/22 16:32:59 by sdummett         ###   ########.fr       */
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
typedef struct s_environ
{
	char				*name;
	char				*value;
	struct s_environ	*next;
}	t_environ;

/*
** Other variables
*/
typedef struct s_global_var
{
	char				*name;
	char				*value;
	struct s_environ	*next;
}	t_global_vars;


/*
** Variables
*/
typedef struct s_vars
{
	t_environ		*env;
	t_global_vars	*var;
	int				last_exit_status;
}	t_vars;

/*
** Builtins
*/
int			cd(char *path);
int			echo(char *text, bool has_newline);
int			pwd(void);
int			export_(t_environ **env,char *name, char *value);
int			unset(t_environ **head, char *varname);
int			env(t_environ *env);
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
void		printenv(t_environ *env); //<-delete printenv.c

#endif
