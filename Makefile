# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nammari <nammari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 21:34:46 by sdummett          #+#    #+#              #
#    Updated: 2021/10/18 10:43:15 by nammari          ###   ########.fr        #
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
CC			= clang
CFLAGS		= -Wall -Werror -Wextra -g3 -fsanitize=address
NAME		= minishell
SRCS_DIR	= srcs/
SRCS_SUB_DIR_BOOLEANS = booelans

BOOLEANS_FILES = $(addprefix booleans/, is_next_assignment.c is_operator.c \
	is_space.c is_whitespace.c is_quote.c is_alpha_num.c is_redirection.c)
ERRORS_FILES = $(addprefix errors/, error_management.c)
TOKENIZE_FILES = $(addprefix tokenize/, checkers_redirection.c free_token_lst.c \
get_cmd_suffix.c get_cmd.c \
get_next_type_operator.c get_pipe.c has_parse_errors.c create_and_push_back.c \
 ft_tokenize.c get_assignment.c get_index_operator.c\
get_op_elem.c get_redirection_op.c)
PARSING_FILES = $(addprefix parsing/, ft_parser.c count_words_nb.c \
get_processed_cmd_line.c get_word.c split_cmd_line.c)
AST_FILES = $(addprefix ast/, ft_create_ast.c)
EXECUTION_FILES = 
BUILTINS_FILES =
UTILS_FILES = $(addprefix utils/, skip_whitespace.c ft_strdup_index.c)

SRCS_FILES	=  minishell.c $(BOOLEANS_FILES) $(ERRORS_FILES) $(TOKENIZE_FILES)\
	 $(PARSING_FILES) $(BUILTINS_FILES) $(UTILS_FILES) $(AST_FILES)

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
OBJS_SUB_DIRECTORIES = $(addprefix objs/, booleans errors tokenize execution \
			ast builtins parsing utils) 

# ************************************ #
#                RULES                 #
# ************************************ #

all: $(NAME)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
	mkdir $(OBJS_SUB_DIRECTORIES)


$(NAME): $(OBJS_DIR) $(OBJ)
	make bonus -C $(LIBRARY)
	@printf "$(WHT)[$(GRN)LIBRARY $(LIBRARY) COMPILED$(WHT)]\n"
	$(CC) $(CFLAGS) -lreadline $(OBJ) -o $(NAME) ft_printf/libftprintf.a
	@printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

bonus: $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o $(NAME)

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
	$(RM) $(NAME_BONUS)
	$(RM) $(OBJS_DIR)
	@printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re: fclean all
