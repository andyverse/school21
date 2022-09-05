SRC_PATH	=	./src/
SRC_NAME	=	ft_memset.c \
				ft_calloc.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_striteri.c \
				ft_strmapi.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
HEADER		=	./includes/
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libft.a

all:	$(NAME)

$(NAME):
	@tput setaf 2
	gcc -c $(CFLAGS) $(SRC) -I$(HEADER)
	ar rc $(NAME) $(OBJ_NAME)
	ranlib $(NAME)
	@tput sgr0

clean:
	@tput setaf 1
	rm -rf $(OBJ_NAME)
	@tput sgr0

fclean:	clean
	@tput setaf 1
	rm -f $(NAME)
	@tput sgr0

re: fclean all