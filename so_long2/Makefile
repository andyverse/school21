CC = gcc

NAME = so_long

LIBFTNAME = libft.a

CFLAGS = -Werror -Wall -Wextra

MINILIBX = -lmlx -framework OpenGL -framework AppKit

OBJS := $(*.o)

SRC =	so_long.c \
		so_long_map_1.c \
		so_long_map_2.c \
		so_long_map_3.c \
		so_long_game_1.c \
		so_long_bonus_1.c \
		so_long_bonus_2.c

HDR =	so_long.h

LIBFTPATH = ./libft/

all: $(NAME)

${NAME}: $(OBJS) $(HDR)
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME}

clean:
	rm -rf *.o
	rm -rf ./libft/*.o
	rm -rf ./libft/gnl_other/*.o
	rm -rf ./libft/ft_printf/*.o
	rm -rf ./libft/ft_printf/sources/*.o

fclean: clean
	rm -f $(LIBFTNAME) ${OBJS} $(NAME)

re: fclean ${NAME}

e:	clean
	${CC} ${CFLAGS} ${SRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME}
