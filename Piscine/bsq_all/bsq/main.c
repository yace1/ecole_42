#include "struct.h"
#define BUFSIZE 4096

char *no_first_line(char *tab)
{
	while (*tab != '\n')
	{
		tab++;
	}
	return (tab);
}

int ft_open(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("not open correctly\n");
	}
	return (fd);
}

char **str_totab(char *str,maxsize data)
{
	char	**tab;
	int		i;
	int		j;
	int		k; 

	i = 0;
	k = 0;
	tab = malloc(sizeof(char*) * data.ymax);
	while (i < data.ymax)
	{	
		tab[i] = malloc(sizeof(char) * data.xmax + 1);
		i++;		
	}
	i = 0;
	
	while (i < data.ymax)
	{
		j = 0;
		while (str[k] != '\n' || '\0')
		{
			tab[i][j] = str[k];
			k++;
			j++;
		}
		tab[i][j] = '\0';
		i++;
		k++;
	}
	return (tab);
}

char *new_join(char *str,char *buf)
{
	int		i;
	int		size;
	char	*new_str;

	size = ft_strlen(str) + ft_strlen(buf) + 1;
	new_str = malloc(sizeof(char) + size + 1);
	*new_str = '\0';
	if (new_str == NULL)
	{
		return (0);
		ft_putstr("join malloc issue\n");
	}
	new_str = ft_strcat(new_str,str);
	new_str = ft_strcat(new_str,buf);
	return (new_str);
}

char *ft_read(char *file)
{
	int		i;
	int		byte;
	int 	fd;
	char	*str;
	char	*store;
	char	*buf;

	byte = 1;
	str = malloc(1);
	buf = (char *)malloc(sizeof(char) * BUFSIZE + 1);
	fd = ft_open(file);
	*str = '\0';
	while (byte > 0)
	{
		byte = read(fd,buf,BUFSIZE-1);
		buf[byte] = '\0';
		if (byte < 0)
			return (0);
		store = new_join(str,buf);
		free(str);
		str = store;
	}
	free(buf);
	return(str);
}

char	*ft_put0(char *str,maxsize data)
{
	str[(data.ymax - 1) * (data.xmax-1)] = '\0';
	return (str);
}

int main(int argc, char **argv)
{
	char	*file;
	int 	i;
	int 	fd;
	char	*str_file;
	char	**tab;
	int		**cash;
	maxsize	data;
	
	i = 1;
	data.xmax = 21;
	data.ymax = 21;
	data.obst = 'o';
	data.plein = 'x';
	data.vide = '.';
	file = argv[i];
	str_file = ft_read(file);
	str_file = no_first_line(str_file);
	str_file = ft_put0(str_file, data);
	printf("sa commence\n");	
	ft_putstr(str_file);
	tab = str_totab(str_file, data);
	ft_putstr("\n");
	i = 0;
	while (i < data.ymax)
	{
		ft_putstr(tab[i]);
		i++;
	}
	ft_putstr("\n");
	cash = malloc(sizeof(int*) * data.ymax);
	while (i < data.ymax)
	{
		cash[i] = malloc(sizeof(int) * (data.xmax));
		i++;
	}
	solve(tab,cash,data);
	i = 0;
	int j = 0;
	//free(str_file);
	return (0);
}
