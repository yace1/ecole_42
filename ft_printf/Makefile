NAME = libftprintf.a

OBJECT = $(SRC:.c=.o)

SRC = ft_printf.c print_func.c

all: $(NAME) 

run: re all
	./a.out
	rm -f $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC)
	ar rc $(NAME) $(OBJECT)
	
clean:
	rm -f $(OBJECT) 
fclean: clean
	rm -f $(NAME)

re: fclean all 