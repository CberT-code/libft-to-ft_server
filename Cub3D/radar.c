/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:23:40 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/15 11:47:50 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_radar(t_radar *R, t_data *D)
{
	R->y = (float)D->P->coord->y;
	R->x = (float)D->P->coord->x;
	R->t = (float)-tan(R->alpha);
	R->b = R->y - R->t * R->x;
	R->width = D->map->x_max * D->mini->t_case;
}

void		radar(t_data *D)
{
	t_radar	R;

	R.alpha = D->P->alpha + M_PI / 6;
	while (R.alpha > D->P->alpha - M_PI / 6)
	{
		init_radar(&R, D);
		while (R.width--)
		{	
			if (R.alpha - M_PI_2 < 0.000001 && R.alpha - M_PI_2 > 0.000001)
				R.y = R.y - sin(R.alpha);
			else
			{
				R.x = R.x + cos(R.alpha);
				R.y = R.t * R.x + R.b;
			}
			if (D->map->tab_map[(int)R.y / D->mini->t_case][(int)R.x / D->mini->t_case] != '1')
				D->P->img->buffer[(int)R.y * (int)D->mini->ligne + (int)(R.x)] = (int)0xFF0000;
			else 
				R.width = 0;
		}
		R.alpha -= M_PI / 3 / D->elem->R[0];
	}
}