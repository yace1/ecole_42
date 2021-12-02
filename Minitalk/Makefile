SRCS= client.c server.c

OBJS= ${SRCS:.c=.o}

LIBFT_A = libft.a

LIBFT_LIB = libft/

MAKELIBFT=	make -C ./libft

LIBFT  = $(addprefix $(LIBFT_LIB), $(LIBFT_A))

PRINTF_A = printf.a

PRINTF_LIB = printf/

PRINTF  = $(addprefix $(PRINTF_LIB), $(PRINTF_A))

MAKEPRINTF = make -C ./printf

MAKELIBFT=	make -C ./libft

CFLAGS= -Wall -Wextra -Werror
NAME = minitalk

all: 		$(NAME)

.c.o:
			@echo Compiling $<
			gcc $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${MAKELIBFT}
			${MAKEPRINTF}
			gcc ${CFLAGS} $(OBJS) $(LIBFT) $(PRINTF)  -o $(NAME)



clean:
			@echo Cleaning out thos old .o
			${MAKELIBFT} clean
			${MAKEPRINTF} clean
			rm -f $(OBJS)

fclean:		clean
			@echo Cleaning out that old $(NAME)
			${MAKELIBFT} fclean
			${MAKEPRINTF} fclean
			rm -f $(NAME)

re:			fclean $(NAME)

out:
			gcc $(CFLAGS) $(SRCS)

run:
			./$(NAME)

exe:
			$(RE) $(RUN)

.PHONY:		all bonus clean fclean re exe out 
		