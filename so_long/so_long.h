#ifndef SO_LONG_H
 #define SO_LONG_H
#include <unistd.h>
#include <stdio.h>
#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"

typedef struct	m_map {
	int		width;
	int		height;
	char	**data;
}				size_map;
size_map	check_map(int fd);
void 		bg_map(int width, int height, void *mlx_ptr, void *win_ptr);
size_t		ft_strlen2(const char *str);
int			ft_strrchr(const char *s, int c);
void		put_element(size_map map, void *win_ptr, void *mlx_ptr);
int			ft_strchr2(const char *s, int c);
char		**ft_split(char const *s, char c);

#endif