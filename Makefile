# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 21:34:46 by sdummett          #+#    #+#              #
#    Updated: 2021/12/03 14:38:17 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ************************************ #
#              VARIABLES               #
# ************************************ #

MAG			= \033[0;35m
WHT			= \033[0;37m
BLK			= \033[0;30m
RED			= \033[0;31m
YEL			= \033[0;33m
GRN			= \033[0;32m
RM			= rm -rf
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3 -fsanitize=address #-v
NAME		= minishell
SRCS_DIR	= srcs/

BOOLEANS_FILES = $(addprefix booleans/, is_next_assignment.c is_operator.c \
	is_space.c is_whitespace.c is_quote.c is_alpha_num.c is_redirection.c)
ERRORS_FILES = $(addprefix errors/, error_management.c)
TOKENIZE_FILES = $(addprefix tokenize/, checkers_redirection.c free_token_lst.c \
get_cmd_suffix.c get_cmd.c init_function_pointer.c group_cmd_and_args.c\
get_pipe.c has_parse_errors.c create_and_push_back.c \
 ft_tokenize.c get_assignment.c get_index_operator.c get_redirection_op.c)
PARSING_FILES = $(addprefix parsing/, ft_parser.c count_words_nb.c \
get_processed_cmd_line.c get_word.c split_cmd_line.c replace_dollar_word.c \
search_dollar_word.c)
EXECUTION_FILES = $(addprefix el_execution/, pipex_execution.c close_pipes.c \
error_management.c free_memory.c get_paths.c init_fd.c init_here_doc.c \
wait_children.c fd_chained_list.c)
BUILTINS_FILES = $(addprefix builtins/, ft_cd.c ft_echo.c ft_env.c ft_exit.c \
			ft_export.c ft_pwd.c ft_unset.c add_variable.c \
			get_variable.c call_getcwd.c get_greatest_len.c is_valid_identifier.c\
			is_in_linkedlst.c)
HISTORY_FILES = $(addprefix history/, update_history.c)
UTILS_FILES = $(addprefix utils/, skip_whitespace.c ft_strdup_index.c)
INIT_FILES = $(addprefix init/, shell_init.c init_env.c)
LST_FILES = $(addprefix lst/, ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c)

SRCS_FILES	=  minishell.c $(BOOLEANS_FILES) $(EXECUTION_FILES) $(ERRORS_FILES) $(TOKENIZE_FILES)\
	 $(PARSING_FILES) $(BUILTINS_FILES) $(UTILS_FILES) $(AST_FILES) $(HISTORY_FILES) $(INIT_FILES)\
	 $(LST_FILES)

SRCS 		= $(addprefix ${SRCS_DIR}, ${SRC_FILES})
OBJS_DIR	= objs/
OBJS_FILES	= $(SRCS_FILES:.c=.o)
OBJ			= $(addprefix ${OBJS_DIR}, ${OBJS_FILES})

NAME_BONUS	= minishell_bonus
SRC_BONUS	= minishell_bonus.c
OBJ_BONUS	= $(SRC_BONUS:.c=.o)
INC			= -Iinclude
includes	= $(wildcard include/*.h)
LIBRARY		= ft_printf
OBJS_SUB_DIRS = $(addprefix objs/, booleans errors tokenize el_execution \
			ast builtins parsing utils history init lst) 

# ************************************ #
#                RULES                 #
# ************************************ #

all: $(NAME)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
	mkdir $(OBJS_SUB_DIRS)


$(NAME): $(OBJS_DIR) $(OBJ)
	make -C $(LIBRARY)
	@printf "$(WHT)[$(GRN)LIBRARY $(LIBRARY) COMPILED$(WHT)]\n"
	$(CC) $(CFLAGS) -lreadline $(OBJ) -o $(NAME) ft_printf/libftprintf.a
	@printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

$(NAME): $(OBJS_DIR) $(OBJ)
	make -C $(LIBRARY)
	@printf "$(WHT)[$(GRN)LIBRARY $(LIBRARY) COMPILED$(WHT)]\n"
	$(CC) $(CFLAGS) -lreadline $(OBJ) -o $(NAME) ft_printf/libftprintf.a
	@printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(include)
	$(CC) $(INC) -c $(CFLAGS) -o $@ $<

clean:
	make clean -sC $(LIBRARY)
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	@printf "$(WHT)[$(YEL)$(NAME) OBJS REMOVED$(WHT)]\n"

fclean: clean
	make fclean -sC $(LIBRARY)
	$(RM) $(NAME)
	$(RM) $(OBJS_DIR)
	@printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re: fclean all
