NAME = push_swap

BONUS = checker

SRCS =	push_swap.c \
		push_swap_NEW.c \
		push_swap_sort.c \
		push_swap_print.c \
		push_swap_list_2.c \
		push_swap_list_1.c \
		push_swap_utilits.c \
		push_swap_NEW_SORT.c \
		push_swap_operations_1.c \
		push_swap_operations_2.c \
		push_swap_sort_utils_1.c \
		push_swap_sort_utils_2.c \
		push_swap_sort_utils_3.c

SRCS_B =	push_swap_checker.c \
			push_swap_checker_1.c \
			push_swap_checker_op1.c \
			push_swap_checker_op2.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.b)

HDR =	header.h

HDR_B =	header_bonus.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@
#	$(RM) $(OBJS)


bonus: $(BONUS)

$(BONUS) : $(OBJS_B)
	$(CC) $(OBJS_B) -o $@
#	$(RM) $(OBJS_B)

e: fclean $(NAME) $(BONUS)
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

%.o:	%.c $(HDR)
	$(CC) $(CFLAGS) -I.$(HDR) -c $< -o $@

%.b:	%.c $(HDR_B)
	$(CC) $(CFLAGS) -I.$(HDR_B) -c $< -o $@
clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re:	fclean $(NAME)

.PHONY:			all clean fclean re'
