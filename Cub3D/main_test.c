#include "cub3d.h"

int		click_mouse(int key)
{
	char  i;

	i = key + '0';
	write(1,&i,1);
	return (0);
}

int		destroy(t_data *data)
{
	ft_error_map("Exit\n", data, 3); 
	return (0);
}

int		refresh_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->mini->img->image);
	mini_map(data, data->elem);
	return (0);
}

int		move(t_data *data)
{
	if (data->player->move_up == 1)
		data->player->pos_y--;
	if (data->player->move_down == 1)
		data->player->pos_y++;
	if (data->player->move_left == 1)
		data->player->pos_x--;
	if (data->player->move_right == 1)
		data->player->pos_x++;
	refresh_img(data);

	return (0);
}

int	key_press(int key, t_data *data)
{
	printf("|%d|\n", key);
	
	if (key == 13)
		data->player->move_up = 1;
	if (key == 0)
		data->player->move_left = 1;
	if (key == 1)
		data->player->move_down = 1;
	if (key == 2)
		data->player->move_right = 1;
	if (key == 53)
		destroy(data);
	move(data);
	/*if (key == 13)
	{
		mini_map(data, data->elem);
		if (!(data->map->tab_map[(int)data->player->pos_x - 1][(int)data->player->pos_y] == '1'))
		{
			data->player->pos_x--;
			mlx_destroy_image(data->mlx_ptr, data->mini->img->image);
			mini_map(data, data->elem);
		}
	}*/
	return (0);
}

int		key_release(int key, t_data *data)
{
	if (key == 13)
		data->player->move_up = 0;
	if (key == 0)
		data->player->move_left = 0;
	if (key == 1)
		data->player->move_down = 0;
	if (key == 2)
		data->player->move_right = 0;
	if (key == 53)
		destroy(data);
	return (0);
}

int		loop_game(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, destroy, data);
	mlx_hook(data->mlx_win, 2, 0, key_press, data);
	mlx_hook(data->mlx_win, 3, 0, key_release, data);
	return (0);
}

int main(int argc, char **argv)
{
	t_data			data;
	unsigned int	c;
	t_image			img;
	t_key			key;

	key.next = NULL;
	data.key = &key;
	data.key->key = 0;
	if (argc != 2)
		return (dprintf(1, "cc\n"));
	parsing(argv[1], &data);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, data.elem->R[0], data.elem->R[1], "CUB3D");
	//mlx_mouse_hook(data->mlx_win, click_mouse, NULL);
	//mlx_hook(data.mlx_win, 3, 0, key_release, NULL);
	//img->image = mlx_new_image(data->mlx_ptr, 50, 50);
	//img->buffer = mlx_get_data_addr(img->image, &img->bpp, &img->size_l, &img->endian);
	//img->buffer[0] = (char)0xffffff;
	//mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img->image, 0, 0); 
	mini_map(&data, data.elem);
	mlx_loop_hook(data.mlx_ptr, loop_game, &data);
	mlx_loop(data.mlx_ptr);
}
