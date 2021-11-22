SRCS= so_long.c so_long_func.c

INCS= fract_ol.h
OBJS= ${SRCS:.c=.o}
OTHER= get_next_line/*.c

MAKEMLX=	${MAKE} -C ./mlx

CFLAGS= -Wall -Wextra -Werror
NAME= so_long

all: 		$(NAME)

.c.o:
			@echo Compiling $<
			gcc $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${MAKEMLX}
			gcc ${CFLAGS} -I./ -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) $(OTHER) -o $(NAME)

bonus:		${NAME}

clean:
			@echo Cleaning out thos old .o
			${MAKEMLX} clean
			rm -f $(OBJS)

fclean:		clean
			@echo Cleaning out that old $(NAME)
			rm -f $(NAME)

re:			fclean $(NAME)

out:
			gcc $(CFLAGS) $(SRCS)

.PHONY:		all bonus clean fclean re
		