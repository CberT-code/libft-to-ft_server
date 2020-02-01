/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:00:21 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/29 18:54:32 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libc.h>

typedef struct	s_image
{
	void	*image;
	int		height;
	int		width;
	int		bpp;
	int		size_l;
	int		endian;
	int 	*buffer;
}				t_image;

typedef struct			data_s
{
	void				*mlx_ptr;
	void				*mlx_win;
}						data_t;

int main(int argc, char **argv)
{
	data_t			data;
	t_image			*img;


	(void)argc;
	img = malloc(sizeof(t_image));
	if (!(data.mlx_ptr = mlx_init()))
		return (EXIT_FAILURE);
	if (!(data.mlx_win = mlx_new_window(data.mlx_ptr, 1000, 500, "CUB3D")))
		return (EXIT_FAILURE);
	//mlx_mouse_hook(data.mlx_win, click_mouse, NULL);
	//mlx_hook(data.mlx_win, 17, 0, destroy, elem);
	//mlx_hook(data.mlx_win, 2, 0, handle_key, NULL);
	//display_map(&data, elem);
	img->image = mlx_new_image(data.mlx_ptr, 1000, 500);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp, &img->size_l, &img->endian);
	img->buffer[0] = (int)0xFF0000;
	img->buffer[1] = (int)0xFF0000;
	img->buffer[2] = (int)0xFF0000;
	//int (*pixel_array)[1000][1]; // prepare le cast
	//pixel_array = (void *)img->buffer; // cast le char * en int[][]
	//for (int i = 0; i < 50; i++)
	//	*pixel_array[50][i] = 250;
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img->image, 0, 0); 
	mlx_loop(data.mlx_ptr);
}