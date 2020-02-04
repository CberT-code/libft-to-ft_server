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


int			calc_distance_vector(t_player *player, int actual_x, int actual_y)
{
	int distance;

	distance = sqrt(pow(player->coord_x - actual_x, 2) + pow(player->coord_y - actual_y, 2));
	return (distance);
}

void		draw_circle(int ligne, t_image *img, t_player *player, int radius, int color)
{
	int		target_x;
	int		target_y;
	int		actual_x;
	int		actual_y;

	target_x = player->coord_x + radius;
	target_y = player->coord_y + radius;
	actual_x = player->coord_x - radius;

    if (img->buffer[target_x + (player->coord_y * ligne)] == (int)0xCBC9C8)
    {
        player->coord_x -= VITESSE;
        return;
    }
    if (img->buffer[player->coord_x + (target_y * ligne)] == (int)0xCBC9C8)
    {
        player->coord_y -= VITESSE;
        return;
    }
    if (img->buffer[actual_x + (player->coord_y * ligne)] == (int)0xCBC9C8)
    {
        player->coord_x += VITESSE;
        return;
    }
    if (img->buffer[ player->coord_x  + ((player->coord_y - radius) * ligne)] == (int)0xCBC9C8)
    {
        player->coord_x += VITESSE;
        return;
    }


	while (actual_x < target_x)
	{
		actual_y = player->coord_y - radius;
		while (actual_y < target_y)
		{
			if (calc_distance_vector(player, actual_x, actual_y) < radius)
				img->buffer[actual_x + (actual_y * ligne) ] = (int)0xFF0000;
			actual_y++;
            
		}
		actual_x++;
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
	draw_circle((data->map->x_max * t_case),data->mini->img, data->player, t_case / 4, (int)0xFF0000);
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
	img->image = mlx_new_image(data->mlx_ptr, x, y);
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
//	printf("la couleur est = %x\n", pixel_array[26991/map->x_max][26991 % map->x_max][0]);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img->image, 0, 0);
}

void		calcul_coord(t_player *player, t_map *map, int t_case)
{
	player->coord_x = (player->pos_x * t_case) + (t_case / 2);
	player->coord_y = (player->pos_y * t_case) + (t_case / 2);
	printf("coord y : %d\n",player->coord_y);
}

void		mini_map(t_data *data, t_elem *elem)
{
	t_mini			*mini;

	mini = malloc(sizeof(t_mini));
	data->mini = mini;
	mini->img = malloc(sizeof(t_image));
	mini->t_case = elem->R[0] / 3 / data->map->x_max;
	while ((mini->t_case * data->map->y_max) > (elem->R[0] / 3) ||
			(mini->t_case * data->map->x_max) > (elem->R[1] / 2))
		mini->t_case--;
	if (mini->t_case < 10)
		printf("Map too big to be displayed %d\n", mini->t_case);
	else
	{
        if (!data->player->coord_x)
		calcul_coord(data->player, data->map, mini->t_case);
		display_map(data, data->map, mini->t_case);
	}
}
