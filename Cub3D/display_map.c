/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:59:15 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/10 14:31:56 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		display_map(t_data *data, t_map *map, int t_case)
{
	int			x;
	int			y;
	t_image		*img;

	y = t_case * map->y_max;
	x = t_case * map->x_max;
	img = data->mini->img;
	img->image = mlx_new_image(data->ptr, x, y);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	data->player->position = (t_case / 2) + ((data->player->pos_x * t_case) + 
			(data->player->pos_y * x * t_case));
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
	printf("data->playerX = %d\n", player->coord->x);
	player->coord->y = (player->pos_y * t_case) + (t_case / 2);
}

void		init_mini(t_data *data, t_elem *elem, t_mini *mini)
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
	data->mini->ligne = mini->t_case * data->map->x_max;

}

void		mini_map(t_data *data, t_elem *elem)
{
	t_mini *mini;

	if (!data->mini)
		init_mini(data, elem, mini);
	mini = data->mini;
	if (mini->t_case < 10)
		printf("Map too big to be displayed %d\n", mini->t_case);
	if (mini->t_case >= 10)
	{
        if (!data->player->coord)
			calcul_coord(data->player, data->map, mini->t_case);
		display_map(data, data->map, mini->t_case);
		mlx_put_image_to_window(data->ptr, data->win, mini->img->image, 0, 0);
	}
}

void		display_player(t_data *data, t_map *map, int t_case)
{
	int			x;
	int			y;
	t_image		*img;
	t_mini		*mini;
	int			i;

	y = t_case * map->y_max;
	x = t_case * map->x_max;
	i = y * x;
	mini = data->mini;
	if (!(data->player->img = ft_calloc(sizeof(t_image), 1)))
		return ;
	img = data->player->img;
	img->image = mlx_new_image(data->ptr, x, y);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	while (i--)
	img->buffer[i] = mini->img->buffer[i];
	data->player->position = (t_case / 2) + ((data->player->pos_x * t_case) + 
			(data->player->pos_y * x * t_case));
	draw_circle(mini->ligne, data->player->img, data, mini->t_case / 3);
	vision(data);
	mlx_put_image_to_window(data->ptr, data->win, data->player->img->image, 0, 0);
}