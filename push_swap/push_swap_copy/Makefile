FLAG = -Wall -Wextra -Werror -g
CC = clang
NAME = push_swap

SRCS =	push_swap.c \
		push_swap_utilits.c \
		push_swap_operations.c

HDR =	header.h

all: $(NAME)

$(NAME):	$(HEADER)
			$(CC) $(FLAG) $(SRCS) -o $(NAME)

r:
	./$(NAME)

fclean :
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
