/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:46:48 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/15 13:00:27 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub3d.h"

void        display_raycast(t_data *D, t_radar *R, int *i)
{
    float a;
    float o;
    float p;
    int h;
	int op;

    int height;

    a = R->y - D->P->coord->y ;
    o = R->x - D->P->coord->x ;
    h = sqrt((a * a) + (o * o));
	op = D->elem->R[1] / h * 6 ;
	
    height = D->elem->R[1] / 2;
	if (*i  == 1)
	printf("cote oppose = %d\n", op);
	if (*i  == 960)
	printf("cote oppose = %d\n", op);
	if (*i == 1920)
	printf("cote oppose = %d\n", op);
	//printf("%d\n",*i);
	//op /= 2;
    while (op--)
        D->img->buffer[height-- * D->elem->R[0] + *i] = 0xFF00FF;

   while (height > 0)
        D->img->buffer[height-- * D->elem->R[0] + *i] = 0x5555FF;
	op = D->elem->R[1] / h * 6;
	//op /= 2;
    height = D->elem->R[1] / 2;
	while (op--)
        D->img->buffer[height++ * D->elem->R[0] + *i] = 0xFF00FF;

   while (height < D->elem->R[1] - 1)
        D->img->buffer[height++ * D->elem->R[0] + *i] = 0x5555FF;
}

void		init_radar_r(t_radar *R, t_data *D)
{
	R->y = (float)D->P->coord->y;
	R->x = (float)D->P->coord->x;
	R->t = (float)-tan(R->alpha);
	R->b = R->y - R->t * R->x;
	R->width = D->map->x_max * D->mini->t_case;
}

void        raycast(t_data *D)
{
    t_radar	R;
	int i;
    
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
				display_raycast(D, &R, &i);
				R.width	= 0;
			}
		}
		i++;
		R.alpha -= M_PI / 3 / D->elem->R[0];
	}
	mlx_put_image_to_window(D->ptr, D->win, D->img->image, 0, 0);
}

void        move_fb(t_data *D)
{
    t_radar	R;
	int i;
    
	i = 0;	

		init_radar_r(&R, D);
		while (i < VITESSE)
		{

				R.x = R.x + cos(R.alpha);
				R.y = R.t * R.x + R.b;
			
			
			if (D->map->tab_map[(int)R.y / D->mini->t_case][(int)R.x / D->mini->t_case] != '1')
			{
				D->P->coord->y = R.y;
				D->P->coord->x = R.x;
			}
			i++;
		}
}