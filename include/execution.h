/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:37:33 by noufel            #+#    #+#             */
/*   Updated: 2021/12/06 15:48:45 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_token {
	char			*value;
	char			**cmd;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_fd_chain {
	int					fd;
	char				*file_name;
	struct s_fd_chain	*next;
}	t_fd_chain;

typedef struct s_command {
	t_fd_chain	*in_head;
	t_fd_chain	*out_head;
	char		**name;
	char		**paths;
	char		**env;
	int			nb;
	int			input_fd;
	int			output_fd;
	int			pid;
	bool		is_here_doc;
	bool		is_first_command;
	bool		is_main_process_cmd;
	bool		is_assign;
}				t_command_vars;

t_fd_chain	*create_elem(int fd, char *file_name);
void	exit_builtin_exec(int pipe[2], int prev_output, t_command_vars *com, t_token **head);
int		pipex_exec_test(int nb_args, t_token **head, char **environ);
int		elem_pushback(t_fd_chain **head, t_fd_chain *elem);
int		_error_(char source);
void	put_error(char *command);
int		mem_free(char **tab, int index, t_command_vars *commands);
void	double_free(char *tab, char *tab2);
char	**get_paths(char *env[]);
int		init_here_doc(char *limiter, t_command_vars *com);
void	close_unused_fds(int pipe_fds[2], int *prev_output, int i, t_command_vars *com);
int		close_pipes(int fd_1, int fd_2);
void	close_fd_chain(t_fd_chain *head, t_command_vars *com);
int		wait_for_children(t_command_vars *com);
int		init_fd_to_commands(t_token *head, t_command_vars *commands);
int 	write_in_fds(t_fd_chain *head);
void	close_unused_fd_chain(t_fd_chain **head);
int		gnl_here_doc(int fd, char **line, int free_all);
void	advance_linked_list_ptr(t_token **head);
void	init_commands_struct(t_command_vars *commands);
void	init_vars_to_minus_one(int *i, int pipe_fds[2], int *prev_output);
char	**get_command(t_token **head);
int     exec_builtin(t_command_vars *commands);

#endif