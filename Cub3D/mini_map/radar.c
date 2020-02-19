/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:23:40 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 15:00:35 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_radar(t_radar *r, t_data *d)
{
	r->y = (double)d->mini->coord->y;
	r->x = (double)d->mini->coord->x;
	r->t = (double)-tan(r->alpha);
	r->b = r->y - r->t * r->x;
	r->width = d->map->x_max * d->mini->t_case;
}

void		radar(t_data *d)
{
	t_radar	r;

	r.alpha = d->p->alpha + M_PI / 6;
	while (r.alpha > d->p->alpha - M_PI / 6)
	{
		init_radar(&r, d);
		while (r.width--)
		{
			if (r.alpha - M_PI_2 < 0.000001 && r.alpha - M_PI_2 > 0.000001)
				r.y = r.y - sin(r.alpha);
			else
			{
				r.x = r.x + cos(r.alpha);
				r.y = r.t * r.x + r.b;
			}
			if (d->map->tab_map[(int)r.y / d->mini->t_case]
			[(int)r.x / d->mini->t_case] != '1')
				d->p->img->buffer[(int)r.y * (int)d->mini->ligne
				+ (int)(r.x)] = (int)0xFF0000;
			else
				r.width = 0;
		}
		r.alpha -= M_PI / 3 / d->elem->r[0];
	}
}
