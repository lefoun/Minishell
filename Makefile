# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 21:34:46 by sdummett          #+#    #+#              #
#    Updated: 2021/10/01 11:33:17 by sdummett         ###   ########.fr        #
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
SRC			= minishell.c ft_parser.c ft_create_ast.c ft_strdup_index.c is_redirection_op.c \
				is_space.c is_whitespace.c ft_tokenize.c get_index_operator.c get_op_elem.c \
				get_next_type_operator.c is_operator.c
OBJ			= $(SRC:.c=.o)
NAME_BONUS	= minishell_bonus
SRC_BONUS	= minishell_bonus.c
OBJ_BONUS	= $(SRC_BONUS:.c=.o)
INC			= -Iinclude
includes	= $(wildcard include/*.h)


# ************************************ #
#                RULES                 #
# ************************************ #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lreadline $(OBJ) -o $(NAME)
	@printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

bonus: $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o $(NAME)

%.o: %.c $(include)
	$(CC) $(INC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	@printf "$(WHT)[$(YEL)$(NAME) OBJS REMOVED$(WHT)]\n"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	@printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re: fclean all
