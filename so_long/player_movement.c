/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:00:05 by ybentaye          #+#    #+#             */
/*   Updated: 2021/11/25 13:33:25 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_right(size_map *map)
{
	if (map->data[map->p_y][map->p_x + 1] != 'C')
		map->nb_key--;
	if (map->data[map->p_y][map->p_x + 1] != 'E')
	{
		map->data[map->p_y][map->p_x + 1] = 'P';
		map->data[map->p_y][map->p_x] = '0';
		map->p_x++;
	}
	put_element(map, *map->info);
}

static void	move_left(size_map *map)
{
	if (map->data[map->p_y][map->p_x - 1] != 'C')
		map->nb_key--;
	if (map->data[map->p_y][map->p_x - 1] != 'E')
	{
		map->data[map->p_y][map->p_x - 1] = 'P';
		map->data[map->p_y][map->p_x] = '0';
		map->p_x++;
	}
	put_element(map, *map->info);
}

static void	move_up(size_map *map)
{
	if (map->data[map->p_y - 1][map->p_x] != 'C')
		map->nb_key--;
	if (map->data[map->p_y - 1][map->p_x] != 'E')
	{
		map->data[map->p_y - 1][map->p_x] = 'P';
		map->data[map->p_y][map->p_x] = '0';
		map->p_y--;
	}
	put_element(map, *map->info);
	printf("après: %s\n", map->data[map->p_y]);
}

static void	move_down(size_map *map)
{
	if (map->data[map->p_y + 1][map->p_x] != 'C')
		map->nb_key--;
	if (map->data[map->p_y + 1][map->p_x] != 'E')
	{
		map->data[map->p_y + 1][map->p_x] = 'P';
		map->data[map->p_y][map->p_x] = '0';
		map->p_y--;
	}
	put_element(map, *map->info);
}

int	deal_key(int key, void *param)
{
	size_map *map;

	map = param;
	if (key == 124 && map->data[map->p_y][map->p_x + 1] != '1')
		move_right(map);
	if (key == 123 && map->data[map->p_y][map->p_x - 1] != '1')
		move_left(map);
	if (key == 126 && map->data[map->p_y - 1][map->p_x] != '1')
		move_up(map);
	if (key == 125 && map->data[map->p_y + 1][map->p_x] != '1')
		move_down(map);
	return (key);
}