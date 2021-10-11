#include <unistd.h>

void putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	c = '0';
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb = nb * -1;
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c += nb;
		write(1, &c, 1);
	}
}

void	ft_show_tab(struct	s_stock_str *par)
{
	int	i;
	int size;

	i = 0;
	while(par[i].str != 0)
	{
		i++;
	}
	size = i;
	i = 0;
	if (size == 0)
	{
		putstr(par[i].str);
		write(1,"\n",1);
		ft_putnbr(par[i].size);
		write(1,"\n",1);
		putstr(par[i].copy);
	}
	while(i < size)
	{
		putstr(par[i].str);
		write(1,"\n",1);
		ft_putnbr(par[i].size);
		write(1,"\n",1);
		putstr(par[i].copy);
		write(1,"\n",1);
		i++;
	}
}
