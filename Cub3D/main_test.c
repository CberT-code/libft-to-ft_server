#include "cub3d.h"

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
	t_data		*data;
	unsigned int	c;
	t_image			*img;


	(void)argc;
	data = malloc(sizeof(t_data));
	img = malloc(sizeof(t_image));
	data->elem = parsing(argv[1]);
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->elem->R[0], data->elem->R[1], "CUB3D");
	//mlx_mouse_hook(data->mlx_win, click_mouse, NULL);
	mlx_hook(data->mlx_win, 17, 0, destroy, data->elem);
	mlx_hook(data->mlx_win, 2, 0, handle_key, NULL);
	//img->image = mlx_new_image(data->mlx_ptr, 50, 50);
	//img->buffer = mlx_get_data_addr(img->image, &img->bpp, &img->size_l, &img->endian);
	//img->buffer[0] = (char)0xffffff;
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img->image, 0, 0); 
	mini_map(data, data->elem);
	mlx_loop(data->mlx_ptr);
}
