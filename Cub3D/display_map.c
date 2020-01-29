/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:59:15 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/29 21:41:51 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		color_square(int i, t_mini *mini, int color, int mult)
{
	int x;
	int y;

	x = -1;
	while (++x < mini->t_case - 1)
	{
		y = -1;
		while (++y < mini->t_case - 1)
			mini->img->buffer[i + y + (x * mini->t_case * mult)] = color;
	}
}

void		map_color_case(t_data *data, int x, int y, int t_case)
{
	t_elem	*elem;
	int		i;

	i = y + (x * (data->elem->map->y_max * t_case));
	elem = data->elem;
	if (y % t_case == 0 || x % t_case == 0)
		data->mini->img->buffer[i] = (int)0x000000;
	else
	{
		if (elem->map->tab_map[x / t_case][y / t_case] == '1' ||
				(y / t_case) >= ft_strlen(elem->map->tab_map[x / t_case]))
			color_square(i, data->mini, (int)0xCBC9C8, elem->map->y_max);
		else if ((x / t_case == data->elem->player->pos_x) &&
				(y / t_case == data->elem->player->pos_y))
			color_square(i, data->mini, (int)0xFF0000, elem->map->y_max);
		else
			color_square(i, data->mini, (int)0xFFFFFF, elem->map->y_max);
	}
}

void		display_map(t_data *data, t_elem *elem, int t_case)
{
	int		x;
	int		y;
	t_image	*img;

	x = t_case * elem->map->x_max;
	y = t_case * elem->map->y_max;
	img = data->mini->img;
	img->image = mlx_new_image(data->mlx_ptr, y, x);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	x = 1;
	while (x <= (t_case * elem->map->x_max))
	{
		y = 1;
		while (y <= (t_case * elem->map->y_max))
		{
			map_color_case(data, x, y, t_case);
			y += t_case;
		}
		x += t_case;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img->image, 0, 0);
}

void		mini_map(t_data *data, t_elem *elem)
{
	t_mini			*mini;

	mini = malloc(sizeof(t_mini));
	data->mini = mini;
	mini->img = malloc(sizeof(t_image));
	mini->t_case = elem->R[0] / 3 / elem->map->y_max;
	while ((mini->t_case * elem->map->x_max) > (elem->R[0] / 3) ||
			(mini->t_case * elem->map->y_max) > (elem->R[1] / 3))
		mini->t_case--;
	if (mini->t_case < 10)
		printf("Map too big to be displayed %d\n", mini->t_case);
	else
		display_map(data, elem, mini->t_case);
}
