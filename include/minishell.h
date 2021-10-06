/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/10/06 15:16:04 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** Includes
*/

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
# include "ft_printf.h"

// Error management

# define MALLOC_ERROR 2
# define CMD_NOT_FOUND 3

//...

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
	FILE_NAME,
	WILDCARD
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
void	get_op_elem(void);
int		get_index_operator(char *arg);
int		get_next_type_operator(int (*func_chercher[6])(char *str, int index, t_token **head), \
				char *arg, int index, t_token **head);

// Get operator
int	get_redir_out_trunc(char *str, int index, t_token **head);
int	get_redir_out_append(char *str, int index, t_token **head);
int	get_redir_input_here_doc(char *str, int index, t_token **head);
int	get_redir_input_file(char *str, int index, t_token **head);
int	get_pipe_cmd_and_suffix(char *str, int index, t_token **head);


// Linked list utils
int	ft_elem_pushback(t_token **head, t_token *elem);
t_token	*ft_create_elem(char *content, int type);


/*
** Boolean
*/
bool	is_space(char c);
bool	is_whitespace(char c);
bool	is_operator(char c);

// Error functions
void	ft_catch_error(bool error_check, int error_cause, char *str);
int	ft_free_tab(char **tab, int error_cause);
#endif
