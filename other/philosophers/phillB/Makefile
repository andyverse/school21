# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chfederi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:24:16 by chfederi          #+#    #+#              #
#    Updated: 2022/06/24 18:24:18 by chfederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS =  phillob.c run.c utils.c utils1.c

OBJS =  $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

 $(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): phillob.h Makefile

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
