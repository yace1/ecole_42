/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:01:19 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/11/27 19:33:44 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_player(t_map *map, t_window info, int i);
static void	put_collectable(t_map *map, t_window info, int i);
static void	put_wall(t_map *map, t_window info, int i);
static void	put_empty(t_map *map, t_window info, int i);

void	put_element(t_map *map, t_window info)
{
	int		i;
	int		start;
	int		tail_size;

	i = 0;
	tail_size = 86;
	while (i < map->height)
	{
		put_player(map, info, i);
		put_wall(map, info, i);
		put_collectable(map, info, i);
		put_empty(map, info, i);
		start = 0;
		if (ft_strchr2(map->data[i], 'E', start) != -1)
		{
			start = ft_strchr2(map->data[i], 'E', start) + 1;
			mlx_put_image_to_window(info.mlx_ptr,
				info.win_ptr, info.img_cprtl,
				start * 86 - 86, i * 86);
		}
		i++;
	}
}

static void	put_player(t_map *map, t_window info, int i)
{
	if (ft_strchr2(map->data[i], 'P', 0) != -1)
	{
		mlx_put_image_to_window(info.mlx_ptr,
			info.win_ptr, info.img_player,
			ft_strchr2(map->data[i], 'P', 0) * 86, i * 86);
		map->p_y = i;
		map->p_x = ft_strchr2(map->data[i], 'P', 0);
	}
}

static void	put_wall(t_map *map, t_window info, int i)
{
	int	start;

	start = 0;
	while (ft_strchr2(map->data[i], '1', start) != -1)
	{
		start = ft_strchr2(map->data[i], '1', start) + 1;
		mlx_put_image_to_window(info.mlx_ptr,
			info.win_ptr, info.img_palm,
			start * 86 - 86, i * 86);
	}
}

static void	put_collectable(t_map *map, t_window info, int i)
{
	int	start;

	start = 0;
	while (ft_strchr2(map->data[i], 'C', start) != -1)
	{
		start = ft_strchr2(map->data[i], 'C', start) + 1;
		mlx_put_image_to_window(info.mlx_ptr,
			info.win_ptr, info.img_coll,
			start * 86 - 86, i * 86);
	}
}

static void	put_empty(t_map *map, t_window info, int i)
{
	int	start;

	start = 0;
	while (ft_strchr2(map->data[i], '0', start) != -1)
	{
		start = ft_strchr2(map->data[i], '0', start) + 1;
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr,
			info.img_sand,
			start * 86 - 86, i * 86);
	}
}
