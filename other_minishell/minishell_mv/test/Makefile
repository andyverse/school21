# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gulwyck <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 18:36:43 by gulwyck           #+#    #+#              #
#    Updated: 2021/11/13 18:36:47 by gulwyck          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SRV 	= server
NAME_CLI 	= client

SRC_SRV 	= server.c
SRC_CLI 	= client.c

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_C_BONUS	= bonus/client.c 
SRC_S_BONUS	= bonus/server.c 

HEADER 		= header/minitalk.h

LIBFT		= libft/libft.a
PRINTF		= ft_printf/libftprintf.a

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -I./$(HEADER)

RM 			= rm -f

OBJ_S		= $(SRC_SRV:.c=.o) 

OBJ_C		= $(SRC_CLI:.c=.o)

OBJ_S_BONUS	= $(SRC_S_BONUS:.c=.o) 

OBJ_C_BONUS	= $(SRC_C_BONUS:.c=.o)

all: lib $(NAME_SRV) $(NAME_CLI)

bonus: lib $(CLIENT_BONUS) $(SERVER_BONUS)

$(NAME_SRV): $(OBJ_S) 
	$(CC) $(FLAGS) $? $(LIBFT) $(PRINTF) -o $@

${NAME_CLI}: ${OBJ_C}
	${CC} ${FLAGS} $? ${LIBFT} ${PRINTF} -o $@

$(SERVER_BONUS): $(OBJ_S_BONUS)
		$(CC) $(FLAGS) $? $(LIBFT) $(PRINTF) -o $@

$(CLIENT_BONUS): $(OBJ_C_BONUS)
		${CC} ${FLAGS} $? ${LIBFT} ${PRINTF} -o $@

%.o: %.c $(HEADER) $(LIBFT) ${PRINTF}
		${CC} $(FLAGS)  -c  $< -o  $@ 

lib:
	make -C libft
	make -C ft_printf

clean:
	make clean -C libft
	make clean -C ft_printf
	${RM} -f $(OBJ_S) $(OBJ_C) $(OBJ_C_BONUS) $(OBJ_S_BONUS)
	

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	${RM} -f ${NAME_SRV} ${NAME_CLI} $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
