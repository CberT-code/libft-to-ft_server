#include "cub3d.h"

typedef struct	s_image
{
	void	*image;
	int		height;
	int		width;
	int		bpp;
	int		size_l;
	int		endian;
	char 	*buffer;
}				t_image;

int		click_mouse(int key)
{
	char  i;

	i = key + '0';
	write(1,&i,1);
	return (0);
}

int	destroy(t_elem *elem)
{
	ft_error_map("Exit\n", elem, 3); 
	return (0);
}

int	handle_key()
{
	return (0);
}


int main(int argc, char **argv)
{
	data_t			data;
	unsigned int	c;
	t_elem			*elem;
	t_image			*img;


	(void)argc;
	elem = parsing(argv[1]);
	img = malloc(sizeof(t_image));
	if (!(data.mlx_ptr = mlx_init()))
		return (EXIT_FAILURE);
	if (!(data.mlx_win = mlx_new_window(data.mlx_ptr, elem->R[0], elem->R[1], "CUB3D")))
		return (EXIT_FAILURE);
	//mlx_mouse_hook(data.mlx_win, click_mouse, NULL);
	//mlx_hook(data.mlx_win, 17, 0, destroy, elem);
	//mlx_hook(data.mlx_win, 2, 0, handle_key, NULL);
	//display_map(&data, elem);
	img->image = mlx_new_image(data.mlx_ptr, 50, 50);
	img->buffer = mlx_get_data_addr(data.mlx_ptr, &img->bpp, &img->size_l, &img->endian);
	img->buffer[0] = (char)0xffffff;
	printf("test\n");
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img->image, 0, 0); 
	mlx_loop(data.mlx_ptr);
}
