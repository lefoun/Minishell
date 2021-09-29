/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/09/29 15:17:09 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

enum e_arg_type {
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
	FILE
};

typedef struct s_ast {
    char    *value;
    int    type;
    struct  s_pepe *left;
    struct  s_pepe *right;
}           t_ast;

typedef struct s_token {
    char    *value;
    int    type;
    struct  s_pepe *next;
}           t_token;

#endif
