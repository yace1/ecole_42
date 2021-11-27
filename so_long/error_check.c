/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:05:06 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/11/27 23:37:19 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_border(t_map *map);
static int	check_player(t_map *map);
static int	check_exit(t_map *map);
static int	check_line_sz(t_map *map);

int	check_error(t_map *map)
{
	char	*error_msg;

	error_msg = "Error\n The map is not valid";
	if (map->data == NULL)
		write(1, error_msg, 28);
	else if (count_key(map) <= 0)
		write(1, error_msg, 28);
	else if (!check_player(map))
		write(1, error_msg, 28);
	else if (!check_border(map))
		write(1, error_msg, 28);
	else if (!check_exit(map))
		write(1, error_msg, 28);
	else if (!check_line_sz(map))
		write(1, error_msg, 28);
	else
		return (1);
	free(map->data);
	exit(0);
}

static int	check_player(t_map *map)
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
			ft_printf("%c", map->data[i][j]);
			if (map->data[i][j] == 'P')
				res++;
			j++;
		}
		ft_printf("\n");
		i++;
	}
	if (res == 1)
		return (res);
	else
		return (0);
}

static int	check_exit(t_map *map)
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
			if (map->data[i][j] == 'E')
				res++;
			j++;
		}
		i++;
	}
	if (res == 1)
		return (res);
	else
		return (0);
}

static int	check_border(t_map *map)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < map->width)
	{
		if (map->data[0][i] != '1' ||
			map->data[map->height - 1][i] != '1')
			res = 0;
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->data[i][0] != '1' ||
			map->data[i][map->width - 1] != '1')
			res = 0;
		i++;
	}
	return (res);
}

static int	check_line_sz(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->data[i]) != map->width)
			return (0);
		i++;
	}
	return (i);
}
