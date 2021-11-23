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
	char		*s;

	i = 0;
	while (i < 1000)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		printf("%s", s);
		map.width = ft_strlen(s);
		i++;
	}
	map.height = i;
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

void put_element(void *mlx_ptr, void *win_ptr, int fd)
{
	char		*s;
	int			i;
	void		*img;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	while (i < 1000)
	{
		printf("ici poto\n");
		s = get_next_line(fd);
		printf("%d\n", ft_strchr2(s, '0'));
		if (s == NULL)
			break ;
		if (ft_strchr2(s, 'C'))
		{
			printf("Heloooo\n");
			img = mlx_xpm_file_to_image(mlx_ptr, "images/hero.xpm", &i, &i);
			printf("x: %d\n", ft_strchr2(s, 'C') * 86);
			printf("y: %d\n",  i * 86);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, i * 86, ft_strchr2(s, 'C') * 86);
		}
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