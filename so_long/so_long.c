/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:12:32 by yacinebenta       #+#    #+#             */
/*   Updated: 2021/11/28 01:44:30 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_window	fill_info(void *mlx_ptr, void *win_ptr
					, t_window info, t_map *map)
{
	int	t_z;

	t_z = 86;
	info.mlx_ptr = mlx_ptr;
	info.win_ptr = win_ptr;
	info.img_sand = mlx_xpm_file_to_image
		(mlx_ptr, "images/sand2.xpm", &t_z, &t_z);
	info.img_player = mlx_xpm_file_to_image
		(mlx_ptr, "images/player.xpm", &t_z, &t_z);
	info.img_palm = mlx_xpm_file_to_image
		(mlx_ptr, "images/palmier.xpm", &t_z, &t_z);
	info.img_coll = mlx_xpm_file_to_image
		(mlx_ptr, "images/clef.xpm", &t_z, &t_z);
	info.img_cprtl = mlx_xpm_file_to_image
		(mlx_ptr, "images/p_close.xpm", &t_z, &t_z);
	map->info = &info;
	return (info);
}

//error a fix: 	
//				-quitter x pressée
int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_window	info;
	int			fd;

	ft_printf("test");
	mlx_ptr = mlx_init();
	info.mlx_ptr = mlx_ptr;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	map = check_map(fd);
	win_ptr = mlx_new_window
		(mlx_ptr, map.width * 86, map.height * 86, "so long");
	info = fill_info(mlx_ptr, win_ptr, info, &map);
	bg_map(map.width, map.height, info);
	put_element(&map, info);
	mlx_key_hook(win_ptr, deal_key, &map);
	mlx_loop(mlx_ptr);
	return (0);
}
