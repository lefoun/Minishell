/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:58:17 by stone             #+#    #+#             */
/*   Updated: 2021/08/14 20:06:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h> // <- to remove
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdbool.h>

void	exec_cmd(char **args, char **path);
char	**ft_split(char const *s, char c);
char	**get_paths(char *cmd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *b, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	rm_n_first_char(char **str, int n);
int		ft_strncmp(const char *str1, const char *str2, size_t count);
int		ft_strlen(char *str);
int		get_next_line(int fd, char **line);
void	free_args_path(char **args, char **path);
void	heredoc(char *limiter, char *cmd1, char *cmd2, char *outfile);
int		cmd(int pipein, int pipeout, char **args, char **path);
void	create_heredoc_tmp_file(char *limiter);

typedef struct s_path
{
	bool	is_absolute;
	bool	is_relative;
	bool	is_dot_slash;
}	t_path;

typedef struct s_heredoc
{
	char	**args1;
	char	**path1;
	char	**args2;
	char	**path2;
	int		fd_heredoc;
	int		fd_out;
	int		pipefd[2];
	int		pid;
	int		process_nb;
}	t_heredoc;

typedef struct s_pipex
{
	char	**args;
	char	**path;
	int		pipefd1[2];
	int		pipefd2[2];
	int		infilefd;
	int		outfilefd;
	int		pid;
	int		process_nb;
}	t_pipex;

typedef struct s_heredoc_infile
{
	char	*heredoc;
	char	*line;
	char	*tmp;
	int		len;
	int		fd;
}	t_heredoc_infile;

#endif