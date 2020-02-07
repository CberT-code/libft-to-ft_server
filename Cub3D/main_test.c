

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
	mlx_destroy_image(data->ptr, data->player->img->image);
	display_player(data, data->map, data->mini->t_case);
	return (0);
}

int		move(t_data *data)
{
	int	t_case;
	int i;

	i = VITESSE;
	t_case = data->mini->t_case;
	while (i--)
	{
		if (data->player->move_up == 1)
			data->player->coord->y--;
		if (data->player->move_down == 1)
			data->player->coord->y++;
		if (data->player->move_left == 1)
			data->player->coord->x--;
		if (data->player->move_right == 1)
			data->player->coord->x++;
		refresh_img(data);
	}

	return (0);
}

int	key_press(int key, t_data *data)
{
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
	mlx_hook(data->win, 17, 0, destroy, data);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	return (0);
}

int main(int argc, char **argv)
{
	t_data			data;
	unsigned int	c;
	t_key			key;

	key.next = NULL;
	data.key = &key;
	data.key->key = 0;
	if (argc != 2)
		return (ft_printf("cc\n"));
	parsing(argv[1], &data);
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, data.elem->R[0], data.elem->R[1], "CUB3D");
	mini_map(&data, data.elem);
	display_player(&data, data.map, data.mini->t_case);
	mlx_loop_hook(data.ptr, loop_game, &data);
	mlx_loop(data.ptr);
}