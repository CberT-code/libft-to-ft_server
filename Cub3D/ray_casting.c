/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:46:48 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/13 21:28:13 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub3d.h"

void        display_raycast(t_data *data, t_radar *R)
{
    float a;
    float o;
    float p;
    int h;
    int height;

 
    a = fabs(data->player->coord->y - R->y);
    o = fabs(data->player->coord->x - R->x);
    h = sqrt(a * o);
    o = h * tan(M_PI_2 / 3);
    height = data->elem->R[1];

    while (p-- > o/2)
        data->img->buffer[height-- * data->elem->R[0] + R->inc] = 0xFF00FF;
         printf("test\n");
   while (height > data->elem->R[1] / 2)
        data->img->buffer[height-- * data->elem->R[0] + R->inc] = 0xFFFFFF;
}

void        raycast(t_data *data)
{
    t_radar	R;

    
    if (!(data->img = ft_calloc(sizeof(t_image), 1)))
		return ;
    data->img->image =  mlx_new_image(data->ptr, data->elem->R[0], data->elem->R[1]);
	data->img->buffer = (int *)mlx_get_data_addr(data->img->image, &data->img->bpp, &data->img->size_l, &data->img->endian);
	
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
            R.inc++;
		}
		R.angle += M_PI / data->elem->R[0];
	}
}