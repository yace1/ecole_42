SERV_SRCS= server.c

CLIENT_SRCS= client.c

SERV_OBJS= ${SERV_SRCS:.c=.o}

CLIENT_OBJS= ${CLIENT_SRCS:.c=.o}

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

NAME_CLIENT = minitalk_client

NAME_SERVE = minitalk_serve

all: 		$(NAME_SERVE)

.c.o:
			@echo Compiling $<
			gcc $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME_SERVE): 	$(SERV_OBJS)
				${MAKELIBFT}
				${MAKEPRINTF}
				gcc ${CFLAGS} $(SERV_OBJS) $(LIBFT) $(PRINTF)  -o $(NAME_SERVE)

client: 	$(CLIENT_OBJS)
			${MAKELIBFT}
			${MAKEPRINTF}
			gcc ${CFLAGS} $(CLIENT_OBJS) $(LIBFT) $(PRINTF)  -o $(NAME_CLIENT)



clean:
			@echo Cleaning out thos old .o
			${MAKELIBFT} clean
			${MAKEPRINTF} clean
			rm -f $(CLIENT_OBJS)
			rm -f $(SERV_OBJS)

fclean:		clean
			@echo Cleaning out that old $(NAME)
			${MAKELIBFT} fclean
			${MAKEPRINTF} fclean
			rm -f $(NAME_CLIENT)
			rm -f $(NAME_SERVE)

re:			fclean $(NAME)

out:
			gcc $(CFLAGS) $(SRCS)

run:
			./$(NAME)

exe:
			$(RE) $(RUN)

.PHONY:		all bonus clean fclean re exe out 
		
