/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:59:15 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/29 02:07:43 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_color_case(data_t *data, t_elem *elem, int *yx, int t_case)
{
	if (yx[1] % t_case == 0 || yx[0] % t_case == 0)
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, yx[1], yx[0], 0x000000);
	else
	{
		if (elem->map->tab_map[yx[0] / t_case][yx[1] / t_case] == '1' ||
	(yx[1] / t_case) >= ft_strlen(elem->map->tab_map[yx[0] / t_case]))
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, yx[1], yx[0], 0xCBC9C8);
		else if (elem->map->tab_map[yx[0] / t_case][(yx[1] / t_case)] == 'N' ||
			elem->map->tab_map[yx[0] / t_case][yx[1] / t_case] == 'E' ||
			elem->map->tab_map[yx[0] / t_case][yx[1] / t_case] == 'S' ||
			elem->map->tab_map[yx[0] / t_case][yx[1] / t_case] == 'W')
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, yx[1], yx[0], 0xFF0000);
		else
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, yx[1], yx[0], 0xFFFFFF);
	}
}

void	display_map(data_t *data, t_elem *elem)
{
	int				yx[2];
	int				t_case;

	t_case = elem->R[0] / 3 / elem->map->x_max;
	while ((t_case * elem->map->x_max) > (elem->R[0] / 3) ||
(t_case * elem->map->y_max) > (elem->R[1] / 3))
		t_case--;
	if (t_case < 10)
		printf("Map too bif to be display %d\n", t_case);
	yx[0] = 1;
	while (yx[0] <= (t_case * elem->map->y_max))
	{
		yx[1] = 1;
		while (yx[1] <= (t_case * elem->map->x_max))
		{
			map_color_case(data, elem, yx, t_case);
			yx[1]++;
		}
		yx[0]++;
	}
}
