/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:46:48 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 01:19:25 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		display_raycast(t_data *d, t_radar *r, int *i, unsigned int color)
{
	float	a;
	float	o;
	float	p;
	float	h;
	float	op;
	int		height;

	a = r->y - d->mini->coord->y ;
	o = r->x - d->mini->coord->x ; 
	h = sqrt((a * a) + (o * o));
	op = d->elem->r[1] / h;
	height = d->elem->r[1] / 2;
	while (op > 0)
	{
		d->img->buffer[(int)height-- * d->elem->r[0] + *i] = color;
		op -= 0.5;
	}
	while (height > 0)
		d->img->buffer[(int)height-- * d->elem->r[0] + *i] = 0x5555FF;
	op = d->elem->r[1] / h * 6;
	op /= 2;
	height = d->elem->r[1] / 2;
	while (op > 0)
	{
		d->img->buffer[(int)height++ * d->elem->r[0] + *i] = color;
		op -= 0.5;
	}
	while (height < d->elem->r[1] - 1)
		d->img->buffer[(int)height++ * d->elem->r[0] + *i] = 0x5555FF;
}

void		init_radar_r(t_radar *r, t_data *d)
{
	r->y = (float)d->mini->coord->y;
	r->x = (float)d->mini->coord->x;
	r->t = (float)-tan(r->alpha);
	r->b = r->y - r->t * r->x;
	r->width = d->map->x_max * d->mini->t_case;
}

// calc_vector(int x, int y, int decal)
// {

// }

void		raycast(t_data *d)
{
	t_radar			r;
	int				i;
	unsigned int	color;

	i = 0;
	if (!(d->img = ft_calloc(sizeof(t_image), 1)))
		return ;
	d->img->image = mlx_new_image(d->ptr, d->elem->r[0], d->elem->r[1]);
	d->img->buffer = (int *)mlx_get_data_addr(d->img->image, &d->img->bpp,
	&d->img->size_l, &d->img->endian);
	r.alpha = d->p->alpha + M_PI / 6;
	while (r.alpha > d->p->alpha - M_PI / 6)
	{
		init_radar_r(&r, d);
		while (r.width--)
		{
			if (r.alpha - M_PI_2 < 0.0001 && r.alpha - M_PI_2 > 0.000001)
				r.y = r.y - sin(r.alpha);
			else
			{
				r.x = r.x + cos(r.alpha);
				r.y = r.t * r.x + r.b;
			}
			if (d->map->tab_map[(int)r.y / d->mini->t_case]
			[(int)r.x / d->mini->t_case] == '1')
			{
				if ((int)r.x % d->mini->t_case == 0)
					color = 0xFF00FF;
				else
					color = 0x550055;
				display_raycast(d, &r, &i, color);
				r.width = 0;
			}
		}
		i++;
		r.alpha -= M_PI / 3 / d->elem->r[0];
	}
	mlx_put_image_to_window(d->ptr, d->win, d->img->image, 0, 0);
}

