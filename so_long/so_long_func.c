/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:34:43 by ybentaye          #+#    #+#             */
/*   Updated: 2021/11/27 19:32:52 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	check_map(int fd)
{
	t_map	map;
	int		i;
	char	*s;
	char	*temp;

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
	count_key(&map);
	check_error(&map);
	return (map);
}

int	count_key(t_map *map)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] == 'C')
				res++;
			j++;
		}
		ft_printf("\n");
		i++;
	}
	map->step = 0;
	map->nb_key = res;
	return (res);
}

void	bg_map(int width, int height, t_window info)
{
	void	*img;
	int		i;
	int		j;
	int		k;
	int		taile_size;

	taile_size = 86;
	k = 0;
	i = 0;
	img = mlx_xpm_file_to_image(info.mlx_ptr, "images/sand2.xpm",
			&taile_size, &taile_size);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			mlx_put_image_to_window(
				info.mlx_ptr, info.win_ptr, img,
				j * taile_size, i * taile_size);
			j++;
		}
		i++;
	}
}

//dir: 1 = up, 2=right, 3= down, 4=left
void	exit_game(t_map *map, int dir)
{
	if (map->nb_key <= 0)
	{
		if (dir == 1)
			map->data[map->p_y - 1][map->p_x] = 'P';
		if (dir == 2)
			map->data[map->p_y][map->p_x + 1] = 'P';
		if (dir == 3)
			map->data[map->p_y + 1][map->p_x] = 'P';
		if (dir == 4)
			map->data[map->p_y][map->p_x - 1] = 'P';
		map->data[map->p_y][map->p_x] = '0';
		put_element(map, *map->info);
		free(map->data);
		exit(0);
	}
}

//void	put_element(t_map *map, t_window info)
// {
// 	int		i;
// 	int		start;
// 	int		tail_size;

// 	i = 0;
// 	tail_size = 86;
// 	while (i < map->height)
// 	{
// 		start = 0;
// 		if (ft_strchr2(map->data[i], 'P', 0) != -1)
// 		{
// 			mlx_put_image_to_window(info.mlx_ptr,
// 				info.win_ptr, info.img_player,
// 				ft_strchr2(map->data[i], 'P', 0) * 86, i * 86);
// 			map->p_y = i;
// 			map->p_x = ft_strchr2(map->data[i], 'P', 0);
// 		}
// 		start = 0;
// 		if (ft_strchr2(map->data[i], 'E', start) != -1)
// 		{
// 			start = ft_strchr2(map->data[i], 'E', start) + 1;
// 			mlx_put_image_to_window(info.mlx_ptr,
// 				info.win_ptr, info.img_cprtl,
// 				start * 86 - 86, i * 86);
// 		}
// 		start = 0;
// 		while (ft_strchr2(map->data[i], '1', start) != -1)
// 		{
// 			start = ft_strchr2(map->data[i], '1', start) + 1;
// 			mlx_put_image_to_window(info.mlx_ptr,
// 				info.win_ptr, info.img_palm,
// 				start * 86 - 86, i * 86);
// 		}
// 		start = 0;
// 		while (ft_strchr2(map->data[i], 'C', start) != -1)
// 		{
// 			start = ft_strchr2(map->data[i], 'C', start) + 1;
// 			mlx_put_image_to_window(info.mlx_ptr,
// 				info.win_ptr, info.img_coll,
// 				start * 86 - 86, i * 86);
// 		}
// 		start = 0;
// 		while (ft_strchr2(map->data[i], '0', start) != -1)
// 		{
// 			start = ft_strchr2(map->data[i], '0', start) + 1;
// 			mlx_put_image_to_window(info.mlx_ptr, info.win_ptr,
// 				info.img_sand,
// 				start * 86 - 86, i * 86);
// 		}
// 		i++;
// 	}
// }
