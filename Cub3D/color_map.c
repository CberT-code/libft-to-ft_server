/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:23:52 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/13 17:42:35 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			calc_dst_vector(t_coord *coord, int actual_x, int actual_y)
{
	int dst;

	dst = sqrt(pow(coord->x - actual_x, 2) + pow(coord->y - actual_y, 2));
	return (dst);
}

void		check_wall(t_data *data, t_coord *target, int radius)
{
	t_map		*map;
	t_coord		*actual;
	int			t_case;

	map = data->map;
	actual = data->player->coord;
	t_case = data->mini->t_case;
	if (map->tab_map[(target->y - 1) / t_case][(actual->x) / t_case] == '1')
		actual->y--;
	if (map->tab_map[(actual->y - radius) / t_case][(actual->x) / t_case] == '1')
		actual->y++;
	if (map->tab_map[actual->y / t_case][(actual->x - radius) / t_case] == '1')
		actual->x++;
	if (map->tab_map[(actual->y - radius) / t_case][(target->x - 1) / t_case] == '1')
		actual->x--;
}

void		draw_circle(int ligne, t_image *img, t_data *data, int radius)
{
	t_coord		target;
	t_coord		actual;

	target.x = data->player->coord->x + radius;
	target.y = data->player->coord->y + radius;
	actual.x = data->player->coord->x - radius;
	check_wall(data, &target, radius);
	while (actual.x <= target.x)
	{
		actual.y = data->player->coord->y - radius;
		while (actual.y <= target.y)
		{
			if (calc_dst_vector(data->player->coord, actual.x, actual.y) < radius)
				img->buffer[actual.x + (actual.y * ligne) ] = (int)0x318CE7;
			actual.y++;
		}
		actual.x++;
	}
}

void		color_square(int i, t_mini *mini, int color, int mult)
{
	int x;
	int y;

	y = -1;
	while (++y < mini->t_case - 1)
	{
		x = -1;
		while (++x < mini->t_case - 1)
			mini->img->buffer[i + x + (y * mini->t_case * mult)] = color;
	}
}

void		map_color_case(t_data *data, int y, int x, int t_case)
{
	t_map	*map;
	int		i;
	int		centre_x;
	int		centre_y;

	i = x + (y * (data->map->x_max * t_case));
		map = data->map;
	if (x % t_case == 0 || y % t_case == 0)
		data->mini->img->buffer[i] = (int)0x000000;
	else
	{
		if (map->tab_map[y / t_case][x / t_case] == '1' ||
				(x / t_case) >= ft_strlen(map->tab_map[y / t_case]))
			color_square(i, data->mini, (int)0xCBC9C8, map->x_max);
		else
			color_square(i, data->mini, (int)0xFFFFFF, map->x_max);
	}
}