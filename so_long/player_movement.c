/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:00:05 by ybentaye          #+#    #+#             */
/*   Updated: 2021/11/27 23:36:45 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_right(t_map *map)
{
	if (map->data[map->p_y][map->p_x + 1] == 'C')
		map->nb_key--;
	if (map->data[map->p_y][map->p_x + 1] != 'E')
	{
		map->data[map->p_y][map->p_x + 1] = 'P';
		map->data[map->p_y][map->p_x] = '0';
		map->p_x++;
		map->step += 1;
		ft_printf("nbr de pas: %d\n", map->step);
	}
	else
		exit_game(map, 2);
	put_element(map, *map->info);
}

static void	move_left(t_map *map)
{
	if (map->data[map->p_y][map->p_x - 1] == 'C')
		map->nb_key--;
	if (map->data[map->p_y][map->p_x - 1] != 'E')
	{
		map->data[map->p_y][map->p_x - 1] = 'P';
		map->data[map->p_y][map->p_x] = '0';
		map->p_x++;
		map->step += 1;
		ft_printf("nbr de pas: %d\n", map->step);
	}
	else
		exit_game(map, 4);
	put_element(map, *map->info);
}

static void	move_up(t_map *map)
{
	if (map->data[map->p_y - 1][map->p_x] == 'C')
		map->nb_key--;
	if (map->data[map->p_y - 1][map->p_x] != 'E')
	{
		map->data[map->p_y - 1][map->p_x] = 'P';
		map->data[map->p_y][map->p_x] = '0';
		map->p_y--;
		map->step += 1;
		ft_printf("nbr de pas: %d\n", map->step);
	}
	else
		exit_game(map, 1);
	put_element(map, *map->info);
}

static void	move_down(t_map *map)
{
	if (map->data[map->p_y + 1][map->p_x] == 'C')
		map->nb_key--;
	if (map->data[map->p_y + 1][map->p_x] != 'E')
	{
		map->data[map->p_y + 1][map->p_x] = 'P';
		map->data[map->p_y][map->p_x] = '0';
		map->p_y--;
		map->step += 1;
		ft_printf("nbr de pas: %d\n", map->step);
	}
	else
		exit_game(map, 3);
	put_element(map, *map->info);
}

int	deal_key(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 2 && map->data[map->p_y][map->p_x + 1] != '1')
		move_right(map);
	if (key == 0 && map->data[map->p_y][map->p_x - 1] != '1')
		move_left(map);
	if (key == 13 && map->data[map->p_y - 1][map->p_x] != '1')
		move_up(map);
	if (key == 1 && map->data[map->p_y + 1][map->p_x] != '1')
		move_down(map);
	if (key == 53)
	{
		free(map->data);
		exit(0);
	}
	return (key);
}
