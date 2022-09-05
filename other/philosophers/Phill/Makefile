# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 22:21:05 by chfederi          #+#    #+#              #
#    Updated: 2022/07/05 17:18:31 by fnochiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = init.c philo.c run.c utils.c utils1.c

OBJS =  $(SRCS:.c=.o)

HEADER = philo.h

CFLAGS = -g -Wall -Wextra -Werror

CC = cc

all: $(NAME)

 $(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): philo.h Makefile

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
