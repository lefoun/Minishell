# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 21:34:46 by sdummett          #+#    #+#              #
#    Updated: 2021/10/22 18:21:48 by sdummett         ###   ########.fr        #
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
SRC			= minishell.c builtins/cd.c builtins/echo.c builtins/env.c builtins/exit.c \
				builtins/export.c builtins/pwd.c builtins/unset.c ft_putstr.c ft_strlen.c \
				ft_strdup.c debug/printenv.c variable_handler.c get_variables_assignations.c \
				debug/create_args.c
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
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
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
