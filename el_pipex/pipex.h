/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:02:12 by nammari           #+#    #+#             */
/*   Updated: 2021/08/02 15:52:31 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_command {
	char	**name;
	char	**paths;
	char	**env;
	int		nb;
	int		input_fd;
	int		output_fd;
	bool	here_doc;
	bool	is_first_command;
}				t_command_vars;

//################### Parsing functions ##################
char	**get_paths(char *env[]);
char	*get_here_doc_content(int fd, char *limiter, char **str);
int		init_here_doc(char *limiter);
int		init_command_fds(t_command_vars *commands, char **argv, int argc);

//################### Errors #############
int		_error_(char source);
int		close_pipes(int fd_1, int fd_2);
void	put_error(char *command);

// #################### Free ##########
int		mem_free(char **tab, int index, t_command_vars *commands);
void	double_free(char *tab, char *tab2);

#endif
