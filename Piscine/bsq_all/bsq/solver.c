#include "struct.h"
//#include <stdlib.h>
//#include <stdio.h>

int	min(int down, int right, int diag)
{
	int	minimum;

	if (down <= right && down <= diag)
		minimum = down;
	else if (right <= diag && right <= down)
		minimum = right;
	else
		minimum = diag;
	return (minimum);
}

void	copy_colone(char **tab, int **cash, maxsize tab_size)
{
	int	i;

	i = 0;
	while (i < tab_size.ymax)
	{
		if (tab[i][tab_size.xmax - 1] == tab_size.obst)
			cash[i][tab_size.xmax - 2] = 0;
		if (tab[i][tab_size.xmax - 1] == tab_size.vide)
			cash[i][tab_size.xmax - 2] = 1;
		i++;
	}
}

void	copy_ligne(char **tab, int **cash, maxsize tab_size)
{
	char	obst;
	char	vide;
	int		i;

	i = 0;
	obst = '0';
	vide = '1';
	while (i < tab_size.xmax - 2)
	{
		if (tab[tab_size.ymax - 2][i] == tab_size.obst)
			cash[tab_size.ymax - 2][i] = 0;
		if (tab[tab_size.ymax - 2][i] == tab_size.vide)
			cash[tab_size.ymax - 2][i] = 1;
		i++;
	}
}

void	solve(char **tab, int **cash, maxsize tab_size)
{
	int	y;
	int	x;

	y = tab_size.ymax - 2;
	x = tab_size.xmax - 2;
	copy_colone(tab, cash, tab_size);
	copy_ligne(tab, cash, tab_size);
	while (y >= 0)
	{
		x = tab_size.xmax - 2;
		while (x >= 0)
		{
			if (tab[y][x] == tab_size.vide)
			{
				cash[y][x] = 1 + min(cash[y + 1][x],
						cash[y][x + 1], cash[y + 1][x + 1]);
			}
			else
				cash[y][x] = 0;
			x--;
		}
		y--;
	}
}

position	table_check(char **tab, int **cash, maxsize tab_size)
{
	int			x;
	int			y;
	position	pos;

	pos.x = 0;
	pos.y = 0;
	pos.max_square = 0;
	x = 0;
	y = 0;
	while (y < tab_size.ymax)
	{
		x = 0;
		while (x < tab_size.xmax)
		{
			if (cash[y][x] > pos.max_square)
			{
				pos.x = x;
				pos.y = y;
				pos.max_square = cash[y][x];
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	new_tab(char **tab, position pos, maxsize tab_size)
{
	int	x;
	int	y;
	int	limit_x;
	int	limit_y;

	limit_x = pos.x + pos.max_square - 1;
	limit_y = pos.y + pos.max_square - 1;
	x = 0;
	y = 0;
	while (y < tab_size.ymax)
	{
		x = 0;
		while (x < tab_size.xmax)
		{
			if ((x >= pos.x && x <= limit_x) && (y >= pos.y && y <= limit_y))
				tab[y][x] = tab_size.plein;
			x++;
		}
		printf("\n");
		y++;
	}
}

/*int	main()
{
	char tab[5][9] = {	"....o...",
						"...o....",
						"o......o",
						"..o.....",
						"..o....."};
	int **cash;
	int cash[5][8] = 	{{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0}};
	int y = 0, x = 0, i = 0;				
	position pos;
	maxsize tab_size;
	tab_size.xmax = 8;
	tab_size.ymax = 5;
	tab_size.vide = '.';
	tab_size.plein = '#';
	tab_size.obst = 'o';
	y = 0;
	x = 0;
	cash = malloc(sizeof(int*) * tab_size.ymax);
	while (i < tab_size.ymax)
	{
		cash[i] = malloc(sizeof(int) * (tab_size.xmax));
		i++;
	}

	solve(tab,cash,tab_size);
	printf("\n");
	while (y < tab_size.ymax)
	{
		x = 0;
		while (x < tab_size.xmax)
		{
			printf("%d ",cash[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}	
	x = 0;
	y = 0;
	printf("\n");
	pos = table_check(tab,cash,tab_size);
	new_tab(tab,pos,tab_size);
	while (y < tab_size.ymax)
	{
		x = 0;
		while (x < tab_size.xmax)
		{
			printf("%c ",tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}	

	
	printf("x: %d, y: %d, size: %d\n",pos.x,pos.y,pos.max_square);
}*/
