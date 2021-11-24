/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:12:32 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/11/24 16:29:33 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, void *param)
{
	size_map *map;

	map = param;
	printf("avant: %s\n", map->data[map->p_y]);
	printf("voici la key: %d\n", key);
	printf("player position: %d %d ", map->p_x, map->p_y);
	if (key == 124 && map->data[map->p_y][map->p_x + 1] != '1')
	{
		map->data[map->p_y][map->p_x + 1] = 'C';
		map->data[map->p_y][map->p_x] = '0';
		map->p_x++;
		put_element(map, *map->info);
		printf("après: %s\n", map->data[map->p_y]);
	}
	if (key == 123 && map->data[map->p_y][map->p_x - 1] != '1')
	{
		map->data[map->p_y][map->p_x - 1] = 'C';
		map->data[map->p_y][map->p_x] = '0';
		map->p_x++;
		put_element(map, *map->info);
		printf("après: %s\n", map->data[map->p_y]);
	}
	if (key == 126 && map->data[map->p_y-1][map->p_x] != '1')
	{
		map->data[map->p_y-1][map->p_x] = 'C';
		map->data[map->p_y][map->p_x] = '0';
		map->p_y--;
		put_element(map, *map->info);
		printf("après: %s\n", map->data[map->p_y]);
	}
	if (key == 125 && map->data[map->p_y+1][map->p_x] != '1')
	{
		map->data[map->p_y+1][map->p_x] = 'C';
		map->data[map->p_y][map->p_x] = '0';
		map->p_y--;
		put_element(map, *map->info);
		printf("après: %s\n", map->data[map->p_y]);
	}
	return(key);
}

window_info fill_info(void *mlx_ptr, void *win_ptr, window_info info, size_map *map)
{
	int tail_size;

	tail_size = 86;
	info.mlx_ptr = mlx_ptr;
	info.win_ptr = win_ptr;
	info.img_sand = mlx_xpm_file_to_image(mlx_ptr, "images/sand2.xpm", &tail_size, &tail_size);
	info.img_player	=mlx_xpm_file_to_image(mlx_ptr, "images/player.xpm", &tail_size, &tail_size);
	info.img_palm	=mlx_xpm_file_to_image(mlx_ptr, "images/palmier.xpm", &tail_size, &tail_size);
	map->info = &info;
	return (info);
}

int	main()
{
	void		*mlx_ptr;
	void		*win_ptr;
	size_map	map;
	window_info	info;
	int			fd; 

	mlx_ptr = mlx_init();
	info.mlx_ptr = mlx_ptr;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	map = check_map(fd);
	win_ptr = mlx_new_window(mlx_ptr, map.width * 86, map.height * 86, "so long");
	info = fill_info(mlx_ptr, win_ptr, info, &map);
	printf("size: %d, %d\n", map.width, map.height);
	bg_map(map.width, map.height, info);
	put_element(&map, info);
	printf("%s\n", map.data[0]);
	mlx_key_hook(win_ptr, deal_key, &map);
	mlx_loop(mlx_ptr);
	return (0);
}