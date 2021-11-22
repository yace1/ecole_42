#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_map check_map(int fd)
{
	size_map	map;
	int			i;
	int			j;
	char		*s;

	i = 0;
	j = 0;
	s = get_next_line(fd);
	j = ft_strlen(s);
	while(s)
	{
		s = get_next_line(fd);
		if ((int)ft_strlen(s) != j)
		{
			map.height = 0;
			map.width = 0;
			return(map);
		}
		printf("%s",s);
		i++;
	}
	printf("%d\n",i+1);
	map.height = i+1;
	map.width = j;
	return(map);
}

void bg_map(int width, int height, void *mlx_ptr, void *win_ptr)
{
	void	*img;
	int		i;
	int		j;
	int		taile_size;

	taile_size = 86;
	img = mlx_xpm_file_to_image(mlx_ptr, "map.ber", &i, &i);
	while(i < height)
	{
		j = 0;
		while(j < width)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, i * taile_size, j * taile_size);
			j++;
		}
		i++;
	}
}

