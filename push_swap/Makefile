SRCS= push_swap.c lst_util.c operation.c algo_min.c parsing.c algo_chunk.c algo_radix.c\
		error_check.c less_nbr.c lst_util2.c

OBJS= ${SRCS:.c=.o}

LIBFT_A = libft.a

LIBFT_LIB = libft/

LIBFT  = $(addprefix $(LIBFT_LIB), $(LIBFT_A))

MAKELIBFT=	make -C ./libft

PRINTF_A = printf.a

PRINTF_LIB = printf/

PRINTF  = $(addprefix $(PRINTF_LIB), $(PRINTF_A))

MAKEPRINTF = make -C ./printf

CFLAGS= -Wall -Wextra -Werror
NAME = push_swap

all: 		$(NAME)

.c.o:
			@echo Compiling $<
			gcc $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${MAKELIBFT}
			${MAKELIBFT} bonus
			${MAKEPRINTF}
			gcc ${CFLAGS} $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
			@echo Cleaning out thos old .o
			${MAKEPRINTF} clean
			${MAKELIBFT} clean
			rm -f $(OBJS)

fclean:		clean
			@echo Cleaning out that old $(NAME)
			${MAKEPRINTF} fclean
			${MAKELIBFT} fclean
			rm -f $(NAME)

re:			fclean $(NAME)

out:
			gcc $(CFLAGS) $(SRCS)

run:
			./$(NAME)

exe:
			$(RE) $(RUN)

.PHONY:		all bonus clean fclean re exe out 
		