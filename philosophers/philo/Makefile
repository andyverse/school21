# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 20:27:35 by fnochiza          #+#    #+#              #
#    Updated: 2022/06/30 04:12:38 by fnochiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	philosophers.c \
		philosophers_1.c \
		philosophers_2.c \
		philosophers_3.c \
		philosophers_utils.c

OBJS =  $(SRCS:.c=.o)

HEADER = philosophers.h

THREAD = -fsanitize=thread

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

 $(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
