#include "mlx.h"
#include "so_long.h"

int	deal_key(int key, void *param)
{
	param = 0;
	printf("voici la key: %d\n", key);
	return(key);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*relative_path;
	int		img_width = 10;
	int		img_height = 10;

	relative_path = "sand.xpm";
	mlx_ptr = mlx_init();
	write (1, "tata\n", 5);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so long");
	write (1, "titi\n", 5);
	img = mlx_xpm_file_to_image(mlx_ptr, relative_path, &img_width, &img_height);
	write (1, "toto\n", 5);

	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	write (1, "tutu\n", 5);
	mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}