# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:24:16 by chfederi          #+#    #+#              #
#    Updated: 2022/07/06 20:53:22 by fnochiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS =	philosophers_bonus.c \
		philosophers_utils_1_bonus.c \
		philosophers_utils_2_bonus.c \
		philosophers_utils_3_bonus.c \
		philosophers_utils_4_bonus.c

OBJS =  $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

HEADER = philosophers_bonus.h

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
