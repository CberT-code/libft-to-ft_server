/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:46:48 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/27 18:26:15 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		display_raycast(t_data *d, double vec, int i, unsigned int color)
{
	printf("%f\n", vec);
	// double	h;
	// double	op;
	// int		height;
	// op = fabs(vec * sin(30) * 400);
	// printf("vec = %f\n", vec);
	// printf("op = %f\n", op);
	// height = d->elem->r[1] / 2;
	// while (op > 0)
	// {
	// 	d->img->buffer[(int)height-- * d->elem->r[0] + i] = color;
	// 	op -= 1;
	// }
	// while (height > 0)
	// 	d->img->buffer[(int)height-- * d->elem->r[0] + i] = 0x5555FF;


	// op = fabs(vec * sin(30) * 400);
	// height = d->elem->r[1] / 2;
	// while (op > 0)
	// {
	// 	d->img->buffer[(int)height++ * d->elem->r[0] + i] = color;
	// 	op -= 1;
	// }
	// while (height < d->elem->r[1] - 1)
	// 	d->img->buffer[(int)height++ * d->elem->r[0] + i] = 0x5555FF;
}


void		init_radar_r(t_radar *r, t_data *d)
{
	r->y = (double)d->p->coord->y;
	r->x = (double)d->p->coord->x;
	r->t = (double)-tan(r->alpha);
	r->b = r->y - r->t * r->x;
	r->width = d->elem->r[1];
}

double			calc_vector_x(t_radar *r, t_data *d,  int calc)
{
	double x;
	double y;

	x = r->x;
	y = r->y;	
	while (d->map->tab_map[(int)y][(int)x] != '1')
	{
		if (r->alpha > M_PI_2 && r->alpha < (M_PI_2 * 3))
			x -= 1;
		else
			x += 1;
		y = r->t * x + r->b;
	}
	return (y);
}
double			calc_vector_y(t_radar *r, t_data *d)
{
	double x;
	double y;

	x = r->x;
	y = r->y;
	while (d->map->tab_map[(int)y][(int)x] != '1')
	{
		if (r->alpha > M_PI && r->alpha < M_2_PI)
			y += 1;
		else
			y -= 1;
		x = (y - r->b) / r->t;
	}
	return (x);
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
	}
	if (vec_y > vec_x)
	 	vec_x = vec_y;
	display_raycast(d, vec_x, i, 0xffffff);

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
		r.alpha -= M_PI / d->elem->r[0];
	}

	mlx_put_image_to_window(d->ptr, d->win, d->img->image, 0, 0);
}

