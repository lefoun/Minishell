/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/11/02 17:48:24 by nammari          ###   ########.fr       */
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
# include <errno.h>
# include "ft_printf.h"
// Error management

# define OP_NOT_FOUND -1
# define MALLOC_ERROR 2
# define CMD_NOT_FOUND 3

//...

enum	e_arg_type {
	CMD_NAME,
	CMD_SUFFIX,
	PIPE,
	VAR,
	REDIR_IN,
	REDIR_HERE_DOC,
	REDIR_OUT_TRUNC,
	REDIR_OUT_APPEND,
	ASSIGN
};

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

/*
** Builtins utils
*/

typedef struct s_ast {
	char			*value;
	int				type;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

typedef struct s_token {
	char			*value;
	char			**cmd;
	int				type;
	struct s_token	*next;
}	t_token;

// function pointer
// typedef int	(*get_redirection[7])(char *arg, t_token **head);

/*
** Parsing functions
*/
t_ast	*ft_create_ast(char *cmd_line);
char	*ft_strdup_index(char *str, int index);
int		ft_parser(char *cmd);
void	get_op_elem(void);
int		get_index_operator(char *arg);

// Tokenizer
void	ft_tokenize(char **args, t_token **head);
int		check_operator_errors(char **args);
int		check_if_multi_operator(char **args);
void	init_function_pointer(int (*get_redirection[])
					(char **, int *, t_token **));
t_token	*group_cmd_and_args(t_token **head);
t_token	*map_lst_till_pipe_or_eol(t_token **head);
// Pre processing
int		count_words_nb(char *cmd_line);
char	**get_prosseced_cmd_line(char *cmd_line);
void	split_cmd_line(char *cmd_line, char **args, int words_nb, t_vars *vars);
char	*get_word(char *cmd_line, int word_length, t_vars *vars);
char	*search_dollar_word(char *word);
char	*replace_dollar_word(char *word, char *dollar_word, t_vars *vars);

// Get operator
int	get_redir_out_trunc(char **args, int *index, t_token **head);
int	get_redir_out_append(char **args, int *index, t_token **head);
int	get_redir_input_here_doc(char **args, int *index, t_token **head);
int	get_redir_input_file(char **args, int *index, t_token **head);
int	get_cmd(char **args, int *index, t_token **head);
int	get_cmd_suffix(char *str, t_token **head);
int	get_pipe_op(char **args, int index, t_token **head);
int get_assignment(char *cmd_line, t_token **head);
int	get_redirection_op(int (*get_redirection[])(char **, int *, t_token **),
							char **args, int *index, t_token **head);

// Linked list utils
int	ft_elem_pushback(t_token **head, t_token *elem);
t_token	*ft_create_elem(char *content, int type);


/*
** Boolean
*/
bool	is_space(char c);
bool	is_whitespace(char c);
bool	is_operator(char c);
bool	is_next_word_assignment(char *cmd_line);
bool	is_quote(char c);
bool	is_alpha_num(char c);
bool	is_redirection(char c);
/*
** Utils
*/
void	skip_whitespace(char *str);
void	free_token_lst(t_token *lst);

// Error functions
int	ft_catch_error(bool error_check, char *str, t_token **head);
int	ft_free_tab(char **tab, int error_cause);

// Test functions
void	print_token(t_token *head);
#endif
