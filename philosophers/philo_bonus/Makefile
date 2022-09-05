# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:24:16 by chfederi          #+#    #+#              #
#    Updated: 2022/06/30 05:00:58 by fnochiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS =  philo_bonus.c \
		philo_utils_1_bonus.c \
		philo_utils_2_bonus.c \
		philo_utils_3_bonus.c

OBJS =  $(SRCS:.c=.o)

HEADER = philo_bonus.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

 $(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
