/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/10/20 17:53:45 by sdummett         ###   ########.fr       */
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
** Builtins
*/
int	cd(char *path);
int	echo(char *text, bool has_newline);
int	pwd(void);
int export_(char *varname, char *value);
int	unset(char *varname);
int	env(void);
int	exit_(void);

/*
** Temporary
*/
int	ft_strlen(char *str); //<- delete ft_strlen.c
void	ft_putstr(char *str); //<-delete ft_putstr.c

#endif
