/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:46:48 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/18 17:37:30 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub3d.h"

void        display_raycast(t_data *D, t_radar *R, int *i, unsigned int color)
{
    float a;
    float o;
    float p;
    float h;
	float op;

    int height;

    a = R->y - D->mini->coord->y ;
    o = R->x - D->mini->coord->x ; 
    h = sqrt((a * a) + (o * o));
	op = D->elem->R[1] / h;
	
    height = D->elem->R[1] / 2;
    while (op > 0)
	{
        D->img->buffer[(int)height-- * D->elem->R[0] + *i] = color;
		op -= 0.5;
	}

   while (height > 0)
        D->img->buffer[(int)height-- * D->elem->R[0] + *i] = 0x5555FF;
	op = D->elem->R[1] / h * 6;
	op /= 2;
    height = D->elem->R[1] / 2;
	 while (op > 0)
	{
       D->img->buffer[(int)height++ * D->elem->R[0] + *i] = color;
	   op -= 0.5;
	}

   while (height < D->elem->R[1] - 1)
        D->img->buffer[(int)height++ * D->elem->R[0] + *i] = 0x5555FF;
}

void		init_radar_r(t_radar *R, t_data *D)
{
	R->y = (float)D->mini->coord->y;
	R->x = (float)D->mini->coord->x;
	R->t = (float)-tan(R->alpha);
	R->b = R->y - R->t * R->x;
	R->width = D->map->x_max * D->mini->t_case;
}

// calc_vector(int x, int y, int decal)
// {

// }

void        raycast(t_data *D)
{
    t_radar	R;
	int i;
	unsigned int color;
    
	i = 0;
    if (!(D->img = ft_calloc(sizeof(t_image), 1)))
		return ;
    D->img->image =  mlx_new_image(D->ptr, D->elem->R[0], D->elem->R[1]);
	D->img->buffer = (int *)mlx_get_data_addr(D->img->image, &D->img->bpp, &D->img->size_l, &D->img->endian);		
    R.alpha = D->P->alpha + M_PI / 6;
	while (R.alpha > D->P->alpha - M_PI / 6)
	{
		init_radar_r(&R, D);
		while (R.width--)
		{
			if (R.alpha - M_PI_2 < 0.0001 && R.alpha - M_PI_2 > 0.000001)
				R.y = R.y - sin(R.alpha);
			else
			{
				R.x = R.x + cos(R.alpha);
				R.y = R.t * R.x + R.b;
			}
			if (D->map->tab_map[(int)R.y / D->mini->t_case][(int)R.x / D->mini->t_case] == '1')
			{
				printf("%d\n",(int)R.y);
				if ((int)R.x % D->mini->t_case == 0) 
					color = 0xFF00FF;
				else
					color = 0x550055;
				display_raycast(D, &R, &i, color);
				R.width	= 0;
			}
		}
		i++;
		R.alpha -= M_PI / 3 / D->elem->R[0];
	}
	mlx_put_image_to_window(D->ptr, D->win, D->img->image, 0, 0);
}

