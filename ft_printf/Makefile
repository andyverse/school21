FLAG = -Wall -Wextra -Werror

NAME = ft_printf

SRC = ft_printf.c \
	  ft_putchar.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_atoi.c \
	  ft_low_hex.c \
	  ft_up_hex.c

OBJ = $(SRC:.c=.o)

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
