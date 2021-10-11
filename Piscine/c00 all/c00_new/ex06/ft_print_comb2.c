#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_coma(int a, int b)
{
	if (! (a == 98 && b == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	print_nbr(int n)
{
	int		a;
	int		b;
	char	c;
	char	d;

	a = n / 10;
	b = n % 10;
	c = '0' + a;
	d = '0' + b;
	write(1, &c, 1);
	write(1, &d, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			if (j > i)
			{	
				print_nbr(i);
				ft_putchar(' ');
				print_nbr(j);
				print_coma(i, j);
			}
			j++;
		}
		i++;
	}	
}
