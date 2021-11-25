# ************************************ #
#                                      #
#              VARIABLES               #
#                                      #
# ************************************ #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -c
NAME		= pipex
NAME_BONUS	= pipex_bonus
SRC			= pipex.c\
			parsing.c\
			mem_free.c errors.c
SRC_BONUS	= pipex_bonus.c parsing_bonus.c\
				mem_free_bonus.c errors_bonus.c
OBJ			= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

all:	$(NAME) $(BONUS)

$(NAME):	$(OBJ)
	make -C libft
	$(CC) $(OBJ) -o $(NAME) libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

bonus: $(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_BONUS)
	make -C libft
	$(CC) $(OBJ_BONUS) -o $(NAME_BONUS) libft/libft.a

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C libft

re: fclean all bonus
