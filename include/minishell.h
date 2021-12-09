/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/12/09 11:05:17 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** Includes
*/
# include <signal.h>
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
# include "pipex_bonus.h"
# include "history.h"
# include "init.h"
# include "execution.h"

# define MAX_FILENAME_LEN 255
# define MAX_PATH_LEN 4096
# define EXPORT 1
# define UNSET 2
# define ASSIGNMENT 3

// Error management
# define OP_NOT_FOUND -1
# define MALLOC_ERROR 2
# define CMD_NOT_FOUND 3

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

typedef struct s_ast {
	char			*value;
	int				type;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

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
t_variable		*get_variable(t_variable *vars, char *varname);
unsigned int	get_greatest_len(char *str1, char *str2);
bool			is_valid_identifier(char *str, int builtin);
char			**get_environment(void);
void			assign_var(char *keyvalue);
int				get_exit_status(char *str, bool *arg_is_numeric);

// ------------- Parsing -----------------
t_ast			*ft_create_ast(char *cmd_line);
char			*ft_strdup_index(char *str, int index);
int				ft_parser(char *cmd);
void			get_op_elem(void);
int				get_index_operator(char *arg);

// ------------- Tokenizer --------------------
void			ft_tokenize(char **args, t_token **head);
int				check_operator_errors(char **args);
int				check_if_multi_operator(char **args);
void			init_function_pointer(int (*get_redirection[])
					(char **, int *, t_token **));
t_token			*group_cmd_and_args(t_token **head);
t_token			*map_lst_till_pipe_or_eol(t_token **head);
t_token			*group_assign(t_token **head);
void			free_assign(t_token **head);

// ------------- Pre processing-------------------
int				count_words_nb(char *cmd_line);
char			**get_processed_cmd_line(char *cmd_line);
void			split_cmd_line(char *cmd_line, char **args,
					int words_nb);
char			*get_word(char *cmd_line, int word_length);
char			*search_dollar_word(char *word);
char			*replace_dollar_word(char *word, char *dollar_word);

// Get operator
int				get_redir_out_trunc(char **args, int *index, t_token **head);
int				get_redir_out_append(char **args, int *index, t_token **head);
int				get_redir_input_here_doc(char **args, int *index,
					t_token **head);
int				get_redir_input_file(char **args, int *index, t_token **head);
int				get_cmd(char **args, int *index, t_token **head);
int				get_cmd_suffix(char *str, t_token **head);
int				get_pipe_op(char **args, int index, t_token **head);
int				get_assignment(char *cmd_line, t_token **head);
int				get_redirection_op(int (*get_redirection[])
					(char **, int *, t_token **),
					char **args, int *index, t_token **head);

// Linked list utils
int				ft_elem_pushback(t_token **head, t_token *elem);
t_token			*ft_create_elem(char *content, int type);

// -------------------- Boolean -------------
bool			is_space(char c);
bool			is_whitespace(char c);
bool			is_operator(char c);
bool			is_next_word_assignment(char *cmd_line);
bool			is_quote(char c);
bool			is_alpha_num(char c);
bool			is_redirection(char c);
bool			is_main_process_builtin(t_command_vars *commands);

// --------------------------- Utils --------------
void			free_token_lst(t_token *lst);

// ------------------ Error functions ------------
int				ft_catch_error(bool error_check, char *str, t_token **head);
int				ft_free_tab(char **tab, int error_cause);

// ------------------------- Free ------------------
void			free_ressources(void);
void			free_environ(char **tofree);
void			free_link(t_variable *tofree);

// Test functions
void			print_token(t_token *head);

// Main func
int				minishell(void);

#endif
