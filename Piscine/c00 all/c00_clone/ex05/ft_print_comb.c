#include <unistd.h>
void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	print_coma(int a, int b, int c)
{
	if (a != 7 || b != 8 || c != 9)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				ft_putchar('0' + a);
				ft_putchar('0' + b);
				ft_putchar('0' + c);
				print_coma(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
