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

int	key_press(int key, t_data *data)
{
	printf("|%d|\n", key);
	if (key == 13)
	{
		mini_map(data, data->elem);
		if (!(data->elem->map->tab_map[(int)data->elem->player->pos_x - 1][(int)data->elem->player->pos_y] == '1'))
		{
			data->elem->player->pos_x--;
			mlx_destroy_image(data->mlx_ptr, data->mini->img->image);
			mini_map(data, data->elem);
		}
	}
	if (key == 0)
	{
		mini_map(data, data->elem);
		if (!(data->elem->map->tab_map[(int)data->elem->player->pos_x][(int)data->elem->player->pos_y - 1] == '1'))
		{
			data->elem->player->pos_y--;
			mlx_destroy_image(data->mlx_ptr, data->mini->img->image);
			mini_map(data, data->elem);
		}
	}
	if (key == 1)
	{
		mini_map(data, data->elem);
		if (!(data->elem->map->tab_map[(int)data->elem->player->pos_x + 1][(int)data->elem->player->pos_y] == '1'))
		{
			data->elem->player->pos_x++;
			mlx_destroy_image(data->mlx_ptr, data->mini->img->image);
			mini_map(data, data->elem);
		}
	}
	if (key == 2)
	{
		mini_map(data, data->elem);
		if (!(data->elem->map->tab_map[(int)data->elem->player->pos_x][(int)data->elem->player->pos_y + 1] == '1'))
		{
			data->elem->player->pos_y++;
			mlx_destroy_image(data->mlx_ptr, data->mini->img->image);
			mini_map(data, data->elem);
		}
	}
	if (key == 53)
		destroy(data->elem);
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
	mlx_hook(data->mlx_win, 2, 0, key_press, data);
	//mlx_hook(data->mlx_win, 3, 0, key_release, NULL);
	//img->image = mlx_new_image(data->mlx_ptr, 50, 50);
	//img->buffer = mlx_get_data_addr(img->image, &img->bpp, &img->size_l, &img->endian);
	//img->buffer[0] = (char)0xffffff;
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img->image, 0, 0); 
	mini_map(data, data->elem);
	mlx_loop(data->mlx_ptr);
	//mlx_loop_hook(data->mlx_ptr, loop_game, NULL)
}
