/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/09/30 21:34:15 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** Includes
*/

# include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <time.h>

enum	e_arg_type {
	CMD,
	CMD_SUFFIX,
	AND,
	OR,
	PIPE,
	VAR,
	REDIR_IN,
	REDIR_HERE_DOC,
	REDIR_OUT_TRUNC,
	REDIR_OUT_APPEND,
	FILE_NAME
};

typedef struct s_ast {
	char			value;
	int				type;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

typedef struct s_token {
	char			*value;
	int				type;
	struct s_token	*next;
}	t_token;

/*
** Parsing functions
*/
t_ast	*ft_create_ast(char *cmd);
char	*ft_strdup_index(char *str, int index);
bool	get_redirection_op(char *str, int index, t_token **head);
int		ft_parser(char *cmd);
t_token *ft_tokenize(char *cmd);

/*
** Boolean
*/
bool	is_space(char c);
bool	is_whitespace(char c);


#endif
