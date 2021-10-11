#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr (int nb)
{
	unsigned int	unsigned_nb;

	if (nb < 0)
	{
		unsigned_nb = (unsigned int)nb;
		ft_putchar('-');
	}	
	else
	{
		unsigned_nb = (unsigned int)nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(unsigned_nb / 10);
		ft_putnbr(unsigned_nb % 10);
	}
	else
	{
		ft_putchar('0' + unsigned_nb);
	}
}
