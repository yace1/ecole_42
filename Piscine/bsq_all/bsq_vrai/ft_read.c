/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:16:16 by ebennace          #+#    #+#             */
/*   Updated: 2021/07/27 15:01:49 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "struct.h"
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);

}
int ft_strline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	alpha(char c)
{
	int	r;

	r = 0;
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		r = 1;
	return (r);
}

int	ft_atoi(char	*str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (alpha(str[i]) == 0 && str[i] != '\0')
	{
	   	if (str[i] >= 48 && str[i] <= 57)
            res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);	
}

void check_plateaux(char *str)
{
	int i;
	// decripte la 1er line
	i = ft_strline(str);
	int line;
	int n;
	int y;
	int m;
	int reference;
	int nb;
	char remplie;
	char obstacles;
	char vide;
	t_maxsize map;
	

	y = 0;
	reference = 0;	
	line = 0;
	m = 0;
	n = 0;
	//trie les diffents caracteres
	remplie = str[i- 1];
	obstacles = str[i - 2];
	vide = str[i - 3];
	printf("(%c) = remplie\n",remplie);
	printf("(%c) = obstacles\n",obstacles);
	printf("(%c) = vide\n",vide);
	
	// creer un tableaux pour rentre le nombre avec son '\0'
	char	nbr[i - 2];

	i = i - 3;
	while (n < i)
	{
		nbr[n] = str[n];
		n++;		
	}
	nbr[n] = '\0';
	// convertie en int
	nb = ft_atoi(nbr);
	printf("%d = nombre de lignes \n",nb);
	
	
	
		
	// decente dans le plateaux 
	//check de la taille de 1er ligne
	while (*str != '\n')
	{
		str++;
	}
	str++;
	//reference = y + reference;
	while (str[reference] != '\n')
	{
		reference++;
	}

	map.xmax = nb;
	map.ymax = reference;
	map.vide = vide;
	map.plein = remplie;
	map.obst = obstacles;
	printf("%d = nombre de caracteres \n",map.ymax);

	// check que les caracters sont bon && check line (taille)
	while (str[m] != '\0')
	{
		while (str[m] != '\n')
		{
			if (str[m] == obstacles || str[m] == vide || str[m] == '\n')
			{
				printf("OK");
			}
			else 
			{
				write(1, "map error\n",11);
				break;
			}
			m++;
		}
		printf("	%d",m - line);
		if (str[m] == '\n')
		{	
			line++;
			printf("	%d\n",line);
		}
	m++;
	}
	if (line != nb)
		write(1, "map error\n",11);		
}
/*
int main()
{
	char str[] = "10.ox\n";
   	check_plateaux(str);
}
*/

