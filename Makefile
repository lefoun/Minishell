# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 21:34:46 by sdummett          #+#    #+#              #
#    Updated: 2021/10/27 21:49:30 by sdummett         ###   ########.fr        #
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
SRCS_SUB_DIR_BOOLEANS = booleans

BUILTINS_FILES = $(addprefix builtins/, cd.c echo.c env.c exit.c \
			export.c pwd.c unset.c variable_handler.c get_variables_assignations.c)
DEBUG_FILES = $(addprefix debug/, printenv.c create_args.c)
UTILS_FILES = $(addprefix utils/, ft_putstr.c ft_strlen.c ft_strdup.c)
SRCS_FILES	=  minishell.c $(BUILTINS_FILES) $(UTILS_FILES) $(DEBUG_FILES)

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
OBJS_SUB_DIRS = $(addprefix objs/, builtins utils debug)

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
