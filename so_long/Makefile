CC = gcc

NAME = so_long.a

LIBFTNAME = libft.a

CFLAGS =

MINILIBX = -lmlx -framework OpenGL -framework AppKit

OBJS := $(*.o)

SRC =	so_long.c \
		so_long_map_1.c \
		so_long_map_2.c \
		so_long_map_3.c

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

bonus: fclean
	make -C ${LIBFTPATH}
	rm -rf so_long.a.dSYM
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SRC} $(MAPTOOLS) ${RENDERSRC} ${RANDOMSRC} ${ENEMYSRC} ${BONUSSRC} ${ANIMATESRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME} -D BONUS=1

fclean: clean
	rm -f $(LIBFTNAME) ${OBJS} $(NAME)

re: fclean ${NAME}

e:	clean
	${CC} ${CFLAGS} ${SRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME}
