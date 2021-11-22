#include "so_long.h"

int	deal_key(int key, void *param)
{
	param = 0;
	printf("voici la key: %d\n", key);
	return(key);
}

int	main()
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*relative_path;
	size_map	map;
	int			fd; 

	relative_path = "images/sand.xpm";
	mlx_ptr = mlx_init();
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	map = check_map(fd);
	win_ptr = mlx_new_window(mlx_ptr, map.width, map.width, "so long");
	bg_map(map.width, map.height, mlx_ptr, win_ptr);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}