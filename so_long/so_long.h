#ifndef SO_LONG_H
 #define SO_LONG_H
#include <unistd.h>
#include <stdio.h>
#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"

typedef struct	m_map {
	int	width;
	int	height;
}				size_map;
size_map	check_map(int fd);
void 		bg_map(int width, int height, void *mlx_ptr, void *win_ptr);
size_t		ft_strlen(const char *str);

#endif