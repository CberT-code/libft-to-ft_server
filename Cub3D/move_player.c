/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:46:34 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/18 17:37:16 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_way(t_data *D)
{
	if (D->P->move == 1)
		D->P->move = M_PI * 2;
	if (D->P->move == 3)
		D->P->move = M_PI_2 / 2 * 7;
	if (D->P->move == 2)
		D->P->move = M_PI_2 * 3;
	if (D->P->move == 6)
		D->P->move = M_PI_2 / 2 * 5;
	if (D->P->move == 4)
		D->P->move = M_PI;
	if (D->P->move == 12)
		D->P->move = M_PI_2 / 2 * 3;
	if (D->P->move == 8)
		D->P->move = M_PI_2;
	if (D->P->move == 9)
		D->P->move = M_PI_2 / 2;
}

void        move_fb(t_data *D)
{
    t_radar	R;
	int i;

	i = 0;	
	init_way(D);
	if (D->P->move > 0)
	{
		R.alpha = D->P->alpha + D->P->move;
		init_radar(&R, D);
		if (R.alpha< 0.0001 && R.alpha > 0.000001)
			R.y = R.y - sin(R.alpha);
		else
		{
			R.x = R.x + cos(R.alpha);
			R.y = R.t * R.x + R.b;
		}
		if (D->map->tab_map[(int)R.y / D->mini->t_case][(int)R.x / D->mini->t_case] != '1')
		{
			D->mini->coord->y = R.y + 0.5;
			D->mini->coord->x = R.x + 0.5;
		}
	}
}