
SRC	=		ft_strlen.c ft_atoi.c ft_isalpha.c ft_tolower.c \
     ft_toupper.c ft_isdigit.c ft_isalnum.c ft_isprint.c \
     ft_isascii.c ft_strncmp.c ft_strchr.c ft_strrchr.c \
     ft_strlcpy.c ft_strlcat.c ft_itoa.c ft_strnstr.c \
	 ft_strjoin.c ft_split.c ft_memcpy.c ft_memset.c \
	 ft_bzero.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	 ft_memcmp.c ft_strdup.c ft_calloc.c ft_substr.c \
	 ft_strtrim.c ft_strmapi.c ft_putchar_fd.c \
	 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	 ft_atol.c get_next_line_bonus.c \
	 get_next_line_utils_bonus.c ft_strcmp.c
	 

BOBO	=	ft_lstmap.c ft_lstiter.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstnew.c ft_lstdelone.c ft_lstclear.c

CC	=		gcc -c

AR	=		ar

ARFLAGS	=	rc

CFLAGS	=	-Wextra -Wall -Werror

NAME	=	libft.a

OBJS	=	$(SRC:.c=.o)

BONU	=	$(BOBO:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)
			ranlib $(NAME)

%.o:		%.c
			$(CC) -o $@ $< $(CFLAGS)

all:		$(NAME)

bonus:		$(BONU)
			$(AR) $(ARFLAGS) $(NAME) $(BONU)
			ranlib $(NAME)

clean:
			rm -rf $(OBJS) $(BONU)
fclean:		clean
			rm -rf $(NAME)

re:			fclean all
