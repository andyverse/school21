FLAG = -Wall -Wextra -Werror

NAME = gnl

FILE_NAME = baudelaire.txt

SRCS = get_next_line.c

BUFFER_SIZE = -D BUFFER_SIZE=43

all: $(NAME)

$(NAME):	$(HEADER)
			gcc $(FLAG) $(BUFFER_SIZE) $(SRCS) -o $(NAME)
			./$(NAME) $(FILE_NAME)

r:
	./$(NAME) $(FILE_NAME)

fclean :
	rm -rf $(NAME) 

re: fclean all

.PHONY: all, clean, fclean, re