# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 23:28:44 by chfederi          #+#    #+#              #
#    Updated: 2022/09/04 22:10:40 by fnochiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	main.c envinit.c utils1.c\
		dash/cmd.c dash/ft_putstr_fd.c dash/ft_split.c dash/ft_strjoin.c dash/ft_strlen.c dash/ft_strncmp.c dash/parse.c dash/ft_isspace.c dash/ft_substr.c dash/ft_calloc.c dash/pipexator.c\
		pwd.c  cd.c utils2.c token.c exit.c ft_atoi.c unset.c open_qo.c open_s.c open_d1.c toklen.c toklen2.c open_d2.c someutil.c

HEADER = minishell.h

OBJS		=	$(SRCS:.c=.o)

CC = gcc  -g -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror
# -g -fsanitize=address
RLFLAGS = -lreadline -I ~/.brew/opt/readline/lib
all:		$(NAME)

$(NAME):	$(OBJS)
				$(CC) -g $(RLFLAGS) $^ -o $@

%.o		:	%.c $(HEADER) Makefile
			$(CC) -c $< -o $@

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
