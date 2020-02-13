/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:46:48 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/13 20:32:58 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub3d.h"

void		init_radar(t_radar *R, t_data *data)
{
	R->y = (float)data->player->coord->y;
	R->x = (float)data->player->coord->x;
	R->t = (float)-tan(R->angle);
	R->b = R->y - R->t * R->x;
	R->width = data->map->x_max * data->mini->t_case;
}

void        display_raycast(t_data *data, t_radar *R)
{
    int a;
    int o;
    int h;

    a = abs(data->player->coord->y - R.y);
    o = abs(data->player->coord->x - R.x);
    h = sqrt(a * o);
    o = h * tan(M_PI_2 / 3)

}

void        raycast(t_data *data)
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
				display_raycast(data, &R);
			else 
				R.width = 0;
		}
		R.angle += M_PI / data->elem->R[0];
	}
}