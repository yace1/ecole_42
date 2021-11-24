#ifndef SO_LONG_H
 #define SO_LONG_H
#include <unistd.h>
#include <stdio.h>
#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"

typedef struct	info {
	int		*mlx_ptr;
	int		*win_ptr;
	void 	*img_player;
	void	*img_sand;
	void	*img_palm;
}				window_info;

typedef struct	m_map {
	int			width;
	int			height;
	int			p_y;
	int			p_x;
	char		**data;
	window_info	*info;
}				size_map;

typedef struct	obj_position {
	int		x;
	int		y;
}				position;

size_map	check_map(int fd);
void 		bg_map(int width, int height, window_info info);
void		deal_event(size_map map, void *win_ptr);
size_t		ft_strlen2(const char *str);
int			ft_strrchr(const char *s, int c);
void		put_element(size_map *map, window_info info);
int			ft_strchr2(const char *s, int c, int start);
char		**ft_split(char const *s, char c);

#endif