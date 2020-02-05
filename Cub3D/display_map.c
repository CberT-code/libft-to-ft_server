/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:59:15 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/03 13:36:38 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int			calc_distance_vector(t_coord *coord, int actual_x, int actual_y)
{
	int dst;

	dst = sqrt(pow(coord->x - actual_x, 2) + pow(coord->y - actual_y, 2));
	return (dst);
}

void		draw_circle(int ligne, t_image *img, t_player *player, int radius)
{
	t_coord		target;
	t_coord		actual;

	target.x = player->coord->x + radius;
	target.y = player->coord->y + radius;
	actual.x = player->coord->x - radius;
	while (actual.x < target.x)
	{
		actual.y = player->coord->y - radius;
		while (actual.y < target.y)
		{
			if (calc_distance_vector(player->coord, actual.x, actual.y) < radius)
				img->buffer[actual.x + (actual.y * ligne) ] = (int)0xFF0000;
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


void		map_color_case(t_data *data, int y, int x, int t_case )
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

void		display_map(t_data *data, t_map *map, int t_case)
{
	int			x;
	int			y;
	int			ligne;
	t_image		*img;

	ligne = t_case * map->x_max;
	y = t_case * map->y_max;
	x = t_case * map->x_max;
	img = data->mini->img;
	img->image = mlx_new_image(data->ptr, x, y);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	data->player->position = (t_case / 2) + ((data->player->pos_x * t_case) + (data->player->pos_y * ligne * t_case));
	y = 1;
	while (y <= (map->y_max * t_case))
	{
		x = 1;
		while (x <= (t_case * map->x_max))
		{
			map_color_case(data, y, x, t_case);
			x += t_case;
		}
		y += t_case;
	}
}

void		calcul_coord(t_player *player, t_map *map, int t_case)
{
	if (!(player->coord = ft_calloc(sizeof(t_coord), 1)))
		return ;
	player->coord->x = (player->pos_x * t_case) + (t_case / 2);
	player->coord->y = (player->pos_y * t_case) + (t_case / 2);
	printf("coord y : %d\n",player->coord->y);
}

void		mini_map(t_data *data, t_elem *elem)
{
	t_mini *mini;

	if (!data->mini)
	{
		if (!(data->mini = ft_calloc(sizeof(t_mini), 1)))
			return ;
		mini = data->mini;
		if (!(mini->img = ft_calloc(sizeof(t_image), 1)))
			return ;
		mini->t_case = elem->R[0] / 3 / data->map->x_max;
		while ((mini->t_case * data->map->y_max) > (elem->R[0] / 3) ||
			(mini->t_case * data->map->x_max) > (elem->R[1] / 2))
			mini->t_case--;
		if (mini->t_case < 10)
		printf("Map too big to be displayed %d\n", mini->t_case);
	}
	if (data->mini->t_case >= 10)
	{
		mini = data->mini;
        if (!data->player->coord)
			calcul_coord(data->player, data->map, mini->t_case);
		display_map(data, data->map, mini->t_case);
		draw_circle((data->map->x_max * mini->t_case),mini->img, data->player, mini->t_case / 3);
		mlx_put_image_to_window(data->ptr, data->win, mini->img->image, 0, 0);
	}
}