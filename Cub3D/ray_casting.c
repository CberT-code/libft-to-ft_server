/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:46:48 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/27 13:42:28 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		display_raycast(t_data *d, double vec, int i, unsigned int color)
{
	double	h;
	double	op;
	int		height;
 
	op = d->elem->r[1] / vec;
	height = d->elem->r[1] / 2;
	while (op > 0)
	{
		d->img->buffer[(int)height-- * d->elem->r[0] + i] = color;
		op -= 0.5;
	}
	while (height > 0)
		d->img->buffer[(int)height-- * d->elem->r[0] + i] = 0x5555FF;
	op = d->elem->r[1] / h * 6;
	op /= 2;
	height = d->elem->r[1] / 2;
	while (op > 0)
	{
		d->img->buffer[(int)height++ * d->elem->r[0] + i] = color;
		op -= 0.5;
	}
	while (height < d->elem->r[1] - 1)
		d->img->buffer[(int)height++ * d->elem->r[0] + i] = 0x5555FF;
}

void		init_radar_r(t_radar *r, t_data *d)
{
	r->y = (double)d->p->coord->y;
	r->x = (double)d->p->coord->x;
	r->t = (double)-tan(r->alpha);
	r->b = r->y - r->t * r->x;
	r->width = d->elem->r[1];
}

double			calc_vector(t_radar *r, t_data *d,  int calc)
{
	double x;
	double y;

	x = r->x;
	y = r->y;

	if (calc == 1)
	{
		while (d->map->tab_map[(int)y][(int)x] != '1')
		{
				printf("%c\n", d->map->tab_map[(int)y][(int)x]);
			printf("y = %d\n", (int)y);
			printf("x = %d\n", (int)y);

			x -= 1;
			y = r->t * x + r->b;
		}
		return (y);
	}
	if (calc == 2)
	{
		while (d->map->tab_map[(int)y][(int)x] != '1')
		{
			x -= 1;
			x = (y - r->b) / r->t;
		}
		return (x);
	}
	return (0);
}

void		display_column(t_radar *r, t_data *d, int i)
{
	double	vec_x;
	double	vec_y;

	init_radar_r(r, d);
	if (r->alpha > M_PI_2)
	{
		vec_x = calc_vector(r, d, 1);
		vec_y = calc_vector(r, d, 2);
		printf("%f\n", vec_x);
	}
	if (vec_y > vec_x)
		vec_x = vec_y;
	//display_raycast(d, vec_x, i, 0xf0f0f0);

}

void		init_img_ray(t_data *d)
{
	if (!(d->img = ft_calloc(sizeof(t_image), 1)))
		return ;
	d->img->image = mlx_new_image(d->ptr, d->elem->r[0], d->elem->r[1]);
	d->img->buffer = (int *)mlx_get_data_addr(d->img->image, &d->img->bpp,
	&d->img->size_l, &d->img->endian);
}

void		browse_column(t_data *d)
{
	t_radar			r;
	unsigned int	color;
	int				i;

	i = 0;
	init_img_ray(d);
	r.alpha = d->p->alpha + M_PI / 6;
	while (r.alpha > d->p->alpha - M_PI / 6)
	{
		display_column(&r, d, i);
		i++;
		r.alpha -= M_PI / 3 / d->elem->r[0];
	}
	mlx_put_image_to_window(d->ptr, d->win, d->img->image, 0, 0);
}

