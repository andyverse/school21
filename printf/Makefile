FLAG = -Wall -Wextra -Werror

NAME = test_print

LIBFT = ./libft/libt.a

FSRC = ./libft/

SRC1 = test.c

SRC = test.c \
	  #ft_strlen.c

HEADER = libft.h

OBJ = $(SRC:.c=.o)

OBJ1 = $(SRC1:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			gcc $(FLAG) -o $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
