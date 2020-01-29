/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:59:15 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/29 19:11:05 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_color_case(t_data *data, int x, int y, int t_case)
{
	t_elem *elem;
	int i;

	i = y + (x * (data->elem->map->y_max * t_case));
	elem = data->elem;
	if (y % t_case == 0 || x % t_case == 0)
			data->mini->img->buffer[i] = (int)0x000000;
	else
	{
		if (elem->map->tab_map[x / t_case][y / t_case] == '1' ||
				(y / t_case) >= ft_strlen(elem->map->tab_map[x / t_case]))
			data->mini->img->buffer[i] = (int)0xCBC9C8;
		else if (elem->map->tab_map[x / t_case][(y / t_case)] == 'N' ||
				elem->map->tab_map[x / t_case][y / t_case] == 'E' ||
				elem->map->tab_map[x / t_case][y / t_case] == 'S' ||
				elem->map->tab_map[x / t_case][y / t_case] == 'W')
			data->mini->img->buffer[i] = (int)0xFF0000;
		else
			data->mini->img->buffer[i] = (int)0xFFFFFF;
	}
}

void		display_map(t_data *data, t_elem *elem, int t_case)
{
	int		x;
	int		y;

	x = t_case * elem->map->x_max;
	y = t_case * elem->map->y_max;
	data->mini->img->image = mlx_new_image(data->mlx_ptr, y, x);
	data->mini->img->buffer = (int *)mlx_get_data_addr(data->mini->img->image,
			&data->mini->img->bpp, &data->mini->img->size_l,
			&data->mini->img->endian);
	x = 0;
	while (x <= (t_case * elem->map->x_max))
	{
		y = 0;
		while (y <= (t_case * elem->map->y_max))
		{
			map_color_case(data, x, y, t_case);
			y++;
		}
		if ( x == (t_case * elem->map->y_max) - 10000)
			while(1)
			{}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mini->img->image, 0, 0); 
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
