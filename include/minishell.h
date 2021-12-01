/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/12/01 16:19:45 by stone            ###   ########.fr       */
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
# include "ft_printf.h"
# include "shell_init.h"
# include "history.h"
// # include "ft_printf.h" <- Add the library

# define MAX_FILENAME_LEN 255
# define MAX_PATH_LEN 4096
# define EXPORT 1
# define UNSET 2

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
}	t_vars;

/* 
** Environment variables is a global linked list
*/
extern t_vars	*variables;

/*
** Builtins functions
*/
int				ft_cd(char **args);
int				ft_echo(char **args);
int				ft_pwd(char **args);
int				ft_export(char **args);
int				ft_unset(char **args);
int				ft_env(char **args);
int				ft_exit(char **args);

/*
** Builtins utils
*/
void			add_variable(t_variable **head, t_variable *new);
char			*call_getcwd(void);
t_vars			*init_env(void);
t_variable		*get_variable(t_variable *vars, char *varname);
unsigned int	get_greatest_len(char *str1, char *str2);
bool			is_valid_identifier(char *str, int builtin);

/*
** Temporary
*/
void			printenv(void); //<-delete printenv.c
char			**create_args(void); //<-delete create_args.c

#endif
