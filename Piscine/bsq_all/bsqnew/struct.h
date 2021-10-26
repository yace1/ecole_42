#ifndef STRUCT_H
#define STRUCT_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct tpoint
{
	int	x;
	int	y;
	int max_square;
}	position;

typedef struct maxsize
{
	int		xmax;
	int		ymax;
	char	vide;
	char	plein;
	char	obst;
}	maxsize;	

int	min(int down, int right, int diag);
void	copy_colone(char **tab, int **cash, maxsize tab_size);
void	copy_ligne(char **tab, int **cash, maxsize tab_size);
void	solve(char **tab, int **cash, maxsize tab_size);
position	table_check(char **tab, int **cash, maxsize tab_size);
void	new_tab(char **tab, position pos, maxsize tab_size);
int	ft_strlen(char *str);
int	ft_strline(char *str);
int	alpha(char c);
int	ft_atoi(char	*str);
//maxsize		check_plateaux(char *str);
maxsize	check_plateaux(char *str);
#endif 
