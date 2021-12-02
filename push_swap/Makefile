SRCS= push_swap.c

OBJS= ${SRCS:.c=.o}

LIBFT_A = libft.a

LIBFT_LIB = libft/

LIBFT  = $(addprefix $(LIBFT_LIB), $(LIBFT_A))

MAKELIBFT=	make -C ./libft

CFLAGS= -Wall -Wextra -Werror
NAME = push_swap

all: 		$(NAME)

.c.o:
			@echo Compiling $<
			gcc $(CFLAGS) -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${MAKELIBFT}
			gcc ${CFLAGS} $(OBJS) $(LIBFT)  -o $(NAME)

clean:
			@echo Cleaning out thos old .o
			${MAKELIBFT} clean
			rm -f $(OBJS)

fclean:		clean
			@echo Cleaning out that old $(NAME)
			rm -f $(NAME)

re:			fclean $(NAME)

out:
			gcc $(CFLAGS) $(SRCS)

run:
			./$(NAME)

exe:
			$(RE) $(RUN)

.PHONY:		all bonus clean fclean re exe out 
		