FLAG = -Wall -Wextra -Werror -O0 -g
CC = clang
NAME = push_swap

SRCS =	push_swap.c \
		push_swap_utilits.c \
		push_swap_operations_1.c \
		push_swap_operations_2.c \
		push_swap_list_1.c \
		push_swap_list_2.c \
		push_swap_print.c \
		push_swap_sort_utils_1.c \
		push_swap_sort_utils_2.c \
		push_swap_sort_utils_3.c \
		push_swap_sort.c

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
