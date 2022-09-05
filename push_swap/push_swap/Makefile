NAME = push_swap

SRCS =	push_swap.c \
		push_swap_utilits.c \
		push_swap_operations_1.c \
		push_swap_operations_2.c \
		push_swap_list_1.c \
		push_swap_list_2.c \
		push_swap_sort_utils_1.c \
		push_swap_sort_utils_2.c \
		push_swap_sort_utils_3.c \
		push_swap_sort.c

OBJS = $(SRCS:.c=.o)

HDR =	header.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

%.o:	%.c $(HDR)
	$(CC) $(CFLAGS) -I.$(HDR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME

re:	fclean $(NAME)

.PHONY:			all clean fclean re
