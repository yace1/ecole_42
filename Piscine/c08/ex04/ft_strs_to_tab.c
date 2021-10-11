#include <stdlib.h>
#include "ft_stock_str.h"
#include "ft_show_tab.c"

int	len(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	str = malloc(sizeof(*src) * len);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct	s_stock_str *ft_strs_to_tab(int ac,char **av)
{
	t_stock_str		*tab;
	int				total_len;
	int				i;
	
	i = 0;
	total_len = 0;
	while (i < ac)
	{
		total_len += len(av[i]);
		i++;
	}
	tab = (t_stock_str *)malloc(sizeof(t_stock_str)*(ac+1) + sizeof(t_stock_str*));
	i = 0;
	while (i < ac)
	{
		tab[i].size = len(av[i]);
		tab[i].str = ft_strdup(av[i]);
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
		tab[i].size = 0;
		tab[i].str = 0;
		tab[i].copy = 0;

	return (tab);
}

int main(int argc, char **argv)
{
	char **str;
	int size = argc - 1, i = 1;
	t_stock_str	*tab;	

	str = malloc(sizeof(char*) * (argc-1));
	while(i < argc)
	{
		str[i-1] = malloc(sizeof(char) * len(argv[i]) +1);
		str[i-1] = ft_strdup(argv[i]);
		i++;
	}
	i = 0;
	
	tab = ft_strs_to_tab(size,str);	
	i = 0;
	ft_show_tab(tab);
}
