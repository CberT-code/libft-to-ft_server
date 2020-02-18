/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:59:15 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/18 22:47:09 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		display_map(t_data *D, t_map *map, int t_case)
{
	int			x;
	int			y;
	t_image		*img;

	y = t_case * map->y_max;
	x = t_case * map->x_max;
	img = D->mini->img;
	img->image = mlx_new_image(D->ptr, x, y);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	y = 1;
	while (y <= (map->y_max * t_case))
	{
		x = 1;
		while (x <= (t_case * map->x_max))
		{
			map_color_case(D, y, x, t_case);
			x += t_case;
		}
		y += t_case;
	}
}

void		calcul_coord(t_player *P, t_mini *mini, int t_case)
{
	if (!(mini->coord = ft_calloc(sizeof(t_coord), 1)))
		return ;
	mini->coord->x = (P->coord->x * t_case) + (t_case / 2);
	printf("mini%d\n", mini->coord->x);
	mini->coord->y = (P->coord->y * t_case) + (t_case / 2);
}

void		init_mini(t_data *D, t_elem *elem, t_mini *mini)
{
	if (!(D->mini = ft_calloc(sizeof(t_mini), 1)))
		return ;
	mini = D->mini;
	if (!(mini->img = ft_calloc(sizeof(t_image), 1)))
		return ;

	mini->t_case = elem->R[0] / 3 / D->map->x_max;
	while ((mini->t_case * D->map->y_max) > (elem->R[0] / 3) ||
		(mini->t_case * D->map->x_max) > (elem->R[1] / 2))
		mini->t_case--;
	D->mini->ligne = mini->t_case * D->map->x_max;

}

void		mini_map(t_data *D, t_elem *elem)
{
	t_mini *mini;

	if (!D->mini)
		init_mini(D, elem, mini);
	mini = D->mini;
	if (mini->t_case < 10)
		printf("Map too big to be displayed %d\n", mini->t_case);
	if (mini->t_case >= 10)
	{
        if (!D->mini->coord)
			calcul_coord(D->P, D->mini, mini->t_case);
		display_map(D, D->map, mini->t_case);
		mlx_put_image_to_window(D->ptr, D->win, mini->img->image, 0, 0);
	}
}

void		display_P(t_data *D, t_map *map, int t_case)
{
	int			x;
	int			y;
	t_image		*img;
	t_mini		*mini;
	int			i;

	y = t_case * map->y_max;
	x = t_case * map->x_max;
	i = y * x;
	mini = D->mini;
	if (!(D->P->img = ft_calloc(sizeof(t_image), 1)))
		return ;
	img = D->P->img;
	img->image = mlx_new_image(D->ptr, x, y);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	while (i--)
	img->buffer[i] = mini->img->buffer[i];
	move_fb(D);
	draw_circle(mini->ligne, D->P->img, D, mini->t_case / 3);
	printf("test\n");
	radar(D);
	mlx_put_image_to_window(D->ptr, D->win, D->P->img->image, 0, 0);
}