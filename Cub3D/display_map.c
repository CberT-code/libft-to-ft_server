/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:59:15 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/31 20:37:04 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void		color_player(int t_case, t_map *map, t_player *player)
{
	i = player->pos_x * t_case + 
	((y / t_case == player->pos_y) &&
				(x / t_case == data->player->pos_x) &&
				data->player->position == 0)
		{
			color_square(i, data->mini, (int)0xFF0000, map->x_max);
	printf("la couleur est la = %x\n", (int)0xFF0000);
			printf("player = %d\n", i);
			//data->player->position = i + (t_case / 2) + (map->x_max * t_case / 2);
	//printf("position joueur = %d\n", data->player->position);
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
	int 		(*pixel_array)[data->map->x_max][1];
	pixel_array = (void *)data->mini->img->buffer;

	i = x + (y * (data->map->x_max * t_case));
		map = data->map;
	if (x % t_case == 0 || y % t_case == 0)
		data->mini->img->buffer[i] = (int)0x000000;
	else
	{
		if (map->tab_map[y / t_case][x / t_case] == '1' ||
				(x / t_case) >= ft_strlen(map->tab_map[y / t_case]))
			color_square(i, data->mini, (int)0xCBC9C8, map->x_max);
		else if ((y / t_case == data->player->pos_y) &&
				(x / t_case == data->player->pos_x) &&
				data->player->position == 0)
		{
			data->player->position = i + t_case / 2 + (map->x_max * t_case / 2);
			color_square(i, data->mini, (int)0xFF0000, map->x_max);
	printf("la couleur est la = %x\n", (int)0xFF0000);
			printf("player = %d\n", i);
			//data->player->position = i + (t_case / 2) + (map->x_max * t_case / 2);
	//printf("position joueur = %d\n", data->player->position);
		}
		else
			color_square(i, data->mini, (int)0xFFFFFF, map->x_max);
	}
}

void		display_map(t_data *data, t_map *map, int t_case)
{
	int			x;
	int			y;
	t_image		*img;


	y = t_case * map->y_max;
	x = t_case * map->x_max;
	img = data->mini->img;
	img->image = mlx_new_image(data->mlx_ptr, x, y);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	
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
		display_map(data, data->map, mini->t_case);
}
