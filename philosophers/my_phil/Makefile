# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:24:16 by chfederi          #+#    #+#              #
#    Updated: 2022/07/04 21:51:20 by fnochiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	philosophers.c \
		philosophers_utils_1.c \
		philosophers_utils_2.c \
		philosophers_utils_3.c \
		philosophers_utils_4.c

OBJS =  $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = philosophers.h

CC = cc

all: $(NAME)

 $(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

e:	fclean all
	rm -f $(OBJS)
