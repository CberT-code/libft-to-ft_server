/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:46:48 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/14 20:09:32 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub3d.h"

void        display_raycast(t_data *data, t_radar *R, int *i)
{
    float a;
    float o;
    float p;
    int h;
	int op;

    int height;

    a = fabs(data->player->coord->y - R->y);
    o = fabs(data->player->coord->x - R->x);
    h = sqrt((a * a) + (o * o));
	op = data->elem->R[1] / h * 6 ;
	
    height = data->elem->R[1] / 2;
	if (*i  == 1)
	printf("cote oppose = %d\n", op);
	if (*i  == 960)
	printf("cote oppose = %d\n", op);
	if (*i == 1920)
	printf("cote oppose = %d\n", op);
	//printf("%d\n",*i);
	//op /= 2;
    while (op--)
        data->img->buffer[height-- * data->elem->R[0] + *i] = 0xFF00FF;

   while (height > 0)
        data->img->buffer[height-- * data->elem->R[0] + *i] = 0x5555FF;
	op = data->elem->R[1] / h * 6;
	//op /= 2;
    height = data->elem->R[1] / 2;
	while (op--)
        data->img->buffer[height++ * data->elem->R[0] + *i] = 0xFF00FF;

   while (height < data->elem->R[1] - 1)
        data->img->buffer[height++ * data->elem->R[0] + *i] = 0x5555FF;
}

void		init_radar_r(t_radar *R, t_data *data)
{
	R->y = (float)data->player->coord->y;
	R->x = (float)data->player->coord->x;
	R->t = (float)-tan(R->angle);
	R->b = R->y - R->t * R->x;
	R->width = data->map->x_max * data->mini->t_case;
}

void        raycast(t_data *data)
{
    t_radar	R;
	int i;
    
	i = 0;
    if (!(data->img = ft_calloc(sizeof(t_image), 1)))
		return ;
    data->img->image =  mlx_new_image(data->ptr, data->elem->R[0], data->elem->R[1]);
	data->img->buffer = (int *)mlx_get_data_addr(data->img->image, &data->img->bpp, &data->img->size_l, &data->img->endian);
    R.angle = data->player->angle - M_PI / 6;
	while (R.angle < data->player->angle + M_PI / 6)
	{
		init_radar_r(&R, data);
		while (R.width--)
		{	
			if (R.angle - M_PI_2 < 0.000001 && R.angle - M_PI_2 > 0.000001)
				R.y = R.y - sin(R.angle);
			else
			{
				R.x = R.x + cos(R.angle);
				R.y = R.t * R.x + R.b;
			}
			if (data->map->tab_map[(int)R.y / data->mini->t_case][(int)R.x / data->mini->t_case] == '1')
			{
				display_raycast(data, &R, &i);
				R.width	= 0;
			}
		}
		//R.angle = data->player->angle + M_PI / 6;
		i++;
		R.angle += M_PI / 3 / data->elem->R[0];
	}
	mlx_put_image_to_window(data->ptr, data->win, data->img->image, 0, 0);
}