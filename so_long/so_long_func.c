#include "so_long.h"

size_t	ft_strlen2(const char *str)
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
		printf("%s", s);
		map.width = ft_strlen2(s);
		i++;
	}
	map.height = i;
	map.data = ft_split(s, '\n');
	return(map);
}

void bg_map(int width, int height, void *mlx_ptr, void *win_ptr)
{
	void	*img;
	int		i = 0;
	int		j = 0;
	int		k;
	int		taile_size;

	taile_size = 86;
	k = 0;
	img = mlx_xpm_file_to_image(mlx_ptr, "images/sand2.xpm", &taile_size, &taile_size);
	while(i < height)
	{
		j = 0;
		while(j < width)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, j * taile_size, i * taile_size);
			j++;
		}
		i++;
	}
}

void put_element(size_map map, void *win_ptr, void *mlx_ptr)
{
	int		i;
	void	*img;

	i = 0;

	printf("ça commence: \n");
	img = mlx_xpm_file_to_image(mlx_ptr, "images/hero.xpm", &i, &i);
	while (i < map.height)
	{
		//printf("ligne: %d, colonne: %d\n", i, ft_strchr2(map.data[i], 'C'));
		if (ft_strchr2(map.data[i], 'C'))
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, ft_strchr2(map.data[i], 'C') * 86, i * 86);
		i++;
	}
}

int	ft_strchr2(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (0);
}