#include "so_long.h"

size_map check_map(int fd)
{
	size_map	map;
	int			i;
	char		*s;
	char		*temp;

	i = 0;
	s = ft_strdup("");
	while (i < 1000)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		s = ft_strjoin(s, temp);
		free(temp);
		i++;
	}
	map.height = i;
	map.data = ft_split(s, '\n');
	map.width = ft_strlen2(map.data[0]);
	return(map);
}

void bg_map(int width, int height, window_info info)
{
	void	*img;
	int		i = 0;
	int		j = 0;
	int		k;
	int		taile_size;

	taile_size = 86;
	k = 0;
	img = mlx_xpm_file_to_image(info.mlx_ptr, "images/sand2.xpm", &taile_size, &taile_size);
	while(i < height)
	{
		j = 0;
		while(j < width)
		{
			mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, img, j * taile_size, i * taile_size);
			j++;
		}
		i++;
	}
}

void put_element(size_map *map, window_info info)
{
	int		i;
	int		start;
	int		tail_size;

	i = 0;
	tail_size = 86;
	while (i < map->height) 
	{
		start = 0;
		if (ft_strchr2(map->data[i], 'C', 0) != -1)
		{
			mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_player, 
			ft_strchr2(map->data[i], 'C', 0) * 86, i * 86);
			map->p_y = i;
			map->p_x = ft_strchr2(map->data[i], 'C', 0);
			printf("player pos: %d %d ", map->p_x, map->p_y);
		}
		while (ft_strchr2(map->data[i], '1', start) != -1)
		{
			start = ft_strchr2(map->data[i], '1', start) + 1;
			mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_palm, start * 86 - 86, i * 86);
		}
		start = 0;
		while (ft_strchr2(map->data[i], '0', start) != -1)
		{
			start = ft_strchr2(map->data[i], '0', start) + 1;
			mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_sand, start * 86 - 86, i * 86);
		}
		i++;
	}
}
