/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:24:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/15 22:09:45 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		click_mouse(int key)
{
	char  i;

	i = key + '0';
	write(1, &i, 1);
	return (0);
}

int		destroy(t_data *D)
{
	ft_error_map("Exit\n", D, 3); 
	return (0);
}

int		refresh_img(t_data *D)
{
	mlx_destroy_image(D->ptr, D->img->image);
	mlx_destroy_image(D->ptr, D->P->img->image);
	raycast(D);
	display_P(D, D->map, D->mini->t_case);
	
	return (0);
}

int		move(t_data *D)
{
	int	t_case;
	int i;

	i = VITESSE;
	t_case = D->mini->t_case;
	while (i--)
	{
		D->P->move = 0;
		if (D->P->move_up == 1)
			D->P->move += 1;
		if (D->P->move_right == 1)
			D->P->move += 2;
		if (D->P->move_down == 1)
			D->P->move += 4;
		if (D->P->move_left == 1)
			D->P->move += 8;
		if (D->P->watch_right == 1)
			D->P->alpha += VITESSEROTATION;
		if (D->P->watch_left == 1)
			D->P->alpha -= VITESSEROTATION;
		if (D->mini->display == 0)
			refresh_img(D);
	}
	return (0);
}

int	key_press(int key, t_data *D)
{
	printf("key = %d\n", key);
	if (key == 13)
		D->P->move_up = 1;
	if (key == 0)
		D->P->move_left = 1;
	if (key == 1)
		D->P->move_down = 1;
	if (key == 2)
		D->P->move_right = 1;
	if (key == 123)
		D->P->watch_right = 1;
	if (key == 124)
		D->P->watch_left = 1;
	if (key == 46)
	{
		D->mini->display = !D->mini->display;
		if (D->mini->display == 1)
			mlx_destroy_image(D->ptr, D->P->img->image);
	}
	if (key == 53)
		destroy(D);
	move(D);
	return (0);
}

int		key_release(int key, t_data *D)
{
	if (key == 13)
		D->P->move_up = 0;
	if (key == 0)
		D->P->move_left = 0;
	if (key == 1)
		D->P->move_down = 0;
	if (key == 2)
		D->P->move_right = 0;
	if (key == 123)
		D->P->watch_right = 0;
	if (key == 124)
		D->P->watch_left = 0;
	if (key == 53)
		destroy(D);
	return (0);
}

int		loop_game(t_data *D)
{
	mlx_hook(D->win, 17, 0, destroy, D);
	mlx_hook(D->win, 2, 0, key_press, D);
	mlx_hook(D->win, 3, 0, key_release, D);
	return (0);
}

int main(int argc, char **argv)
{
	t_data			D;
	unsigned int	c;
	t_key			key;

	key.next = NULL;
	D.key = &key;
	D.key->key = 0;
	if (argc != 2)
		return (ft_printf("cc\n"));
	parsing(argv[1], &D);
	D.ptr = mlx_init();
	D.win = mlx_new_window(D.ptr, D.elem->R[0], D.elem->R[1], "CUB3D");
	mini_map(&D, D.elem);
	raycast(&D);
	display_P(&D, D.map, D.mini->t_case);
	
	mlx_loop_hook(D.ptr, loop_game, &D);
	mlx_loop(D.ptr);
}