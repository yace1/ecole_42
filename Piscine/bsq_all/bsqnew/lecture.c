/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 21:13:24 by ebennace          #+#    #+#             */
/*   Updated: 2021/07/27 21:37:31 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include <stdio.h>
#include <fcntl.h>
#include "struct.h"

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char **store_map(char *buf, maxsize data)
{
	char	**tab;
	int		i;
	int		y;
	int 	k;

	i = 6;
	y = 0;
	tab = malloc(sizeof(char *) * (data.ymax));
	if (tab == NULL)
		exit (0);
	while (buf[i] != '\0')
	{
		k = 0;
		while (buf[i] != '\n')
		{
			k++;
			i++;
		}
		tab[y] = malloc(sizeof(char) * (k+3));		
		y++;
		i++;
	}
	i = 6;
	y = 0;
	while (buf[i] != '\0')
	{
		k = 0;
		while (buf[i] != '\n')
		{
			tab[y][k] = buf[i];
			k++;
			i++;
		}	
		y++;
		i++;
	}
	return (tab);
}


//maxsize check_plateaux(char *str);
int main()
{	
	int		fd;
	int		ret;
	int		i;
	char	buf[4096 + 1];
	char	**tab;
	int		**cash;
	maxsize data;

	i = 0;
	fd = open("test3.txt", O_RDONLY);
	ret = read(fd, buf, 4096);
	buf[ret] = '\0';
	printf("%s\n", buf);

	data = check_plateaux(buf);
	printf("xmax %d, ymax%d\n",data.xmax,data.ymax);
	tab = store_map(buf,data); //stock tableau
	printf("%d",data.ymax);
	while (i < data.ymax-1)
	{
		ft_putstr(tab[i]);
		printf("\n");
		i++;
	}
	cash = malloc(sizeof(int*) * (data.ymax + 1));
	while (i < data.ymax)
	{
		cash[i] = malloc(sizeof(int) * (data.xmax + 1));
		i++;
	}
	solve(tab,cash,data);
}
