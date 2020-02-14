/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:23:40 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/14 19:55:59 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_radar(t_radar *R, t_data *data)
{
	R->y = (float)data->player->coord->y;
	R->x = (float)data->player->coord->x;
	R->t = (float)-tan(R->angle);
	R->b = R->y - R->t * R->x;
	R->width = data->map->x_max * data->mini->t_case;
}

void		radar(t_data *data)
{
	t_radar	R;

	R.angle = data->player->angle - M_PI / 6;
	while (R.angle < data->player->angle + M_PI / 6)
	{
		init_radar(&R, data);
		while (R.width--)
		{	
			if (R.angle - M_PI_2 < 0.000001 && R.angle - M_PI_2 > 0.000001)
				R.y = R.y - sin(R.angle);
			else
			{
				R.x = R.x + cos(R.angle);
				R.y = R.t * R.x + R.b;
			}
			if (data->map->tab_map[(int)R.y / data->mini->t_case][(int)R.x / data->mini->t_case] != '1')
				data->player->img->buffer[(int)R.y * (int)data->mini->ligne + (int)(R.x)] = (int)0xFF0000;
			else 
				R.width = 0;
		}
		R.angle += M_PI / 3 / data->elem->R[0];
	}
}