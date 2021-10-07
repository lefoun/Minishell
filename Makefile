# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nammari <nammari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 21:34:46 by sdummett          #+#    #+#              #
#    Updated: 2021/10/06 18:28:05 by nammari          ###   ########.fr        #
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
RM			= rm -f
CC			= clang
CFLAGS		= -Wall -Werror -Wextra -g3 -fsanitize=address
NAME		= minishell
SRCS_DIR	= srcs/
SRCS_FILES	= minishell.c ft_parser.c ft_create_ast.c ft_strdup_index.c\
				get_redirection_op.c is_space.c is_whitespace.c ft_tokenize.c\
				get_index_operator.c get_op_elem.c get_next_type_operator.c\
				is_operator.c linked_list_utils.c parsing_ast_get_pipe.c\
				error_management.c parsing_ast_get_cmd_name_suffix.c
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


# ************************************ #
#                RULES                 #
# ************************************ #

all: $(NAME)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJ)
	make bonus -sC $(LIBRARY)
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
	@printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re: fclean all
