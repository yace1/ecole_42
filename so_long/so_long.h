/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:34:46 by ybentaye          #+#    #+#             */
/*   Updated: 2021/11/27 18:58:47 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"

typedef struct info {
	int		*mlx_ptr;
	int		*win_ptr;
	void	*img_player;
	void	*img_sand;
	void	*img_palm;
	void	*img_coll;
	void	*img_cprtl;
}				t_window;

typedef struct m_map {
	int			width;
	int			height;
	int			p_y;
	int			p_x;
	int			step;
	int			nb_key;
	char		**data;
	t_window	*info;
}			t_map;

t_map	check_map(int fd);
void	bg_map(int width, int height, t_window info);
void	deal_event(t_map map, void *win_ptr);
size_t	ft_strlen2(const char *str);
int		ft_strrchr(const char *s, int c);
void	put_element(t_map *map, t_window info);
int		ft_strchr2(const char *s, int c, int start);
char	**ft_split(char const *s, char c);
int		deal_key(int key, void *param);
void	exit_game(t_map *map, int dir);
int		count_key(t_map *map);
int		check_error(t_map *map);

#endif