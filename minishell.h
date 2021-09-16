/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:50:54 by noufel            #+#    #+#             */
/*   Updated: 2021/09/16 17:50:48 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

enum e_arg_type {
    WORD,
    OPERATOR,
    PIPE,
    CMD,
};

// struct s_pepe {
//     char    *value;
//     int_8     type;
//     struct  s_pepe *next;
// };

struct s_pepe {
    char    *value;
    int    type;
    struct  s_pepe *left;
    struct  s_pepe *right;
}           t_pepe;

/*******************************/

// struct	*
// {
// 	struct	*s_or_operator;
// 	struct	*s_and_operator
// }	t_pipe_sequence;

// struct	s_pipe_sequence
// {
// 	struct	*s_command_name;
// 	struct	*s_command_suffix;
// }	t_pipe_sequence;

// struct s_ast
// {
// 	struct	*s_pipe_sequence;
// 	struct	*s_or_operator;
// 	struct	*s_and_operator;
// }	t_ast;



#endif
