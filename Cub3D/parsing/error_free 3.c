/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:46:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/30 03:26:33 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		free_elem(t_data *data)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (data->elem->bit_elem & (1 << i++))
			free(data->elem->texture[i - 1]);
	}
	free(data->elem->texture);
	free(data->map);
	free(data->player);
	free(data->elem);
}

void		*ft_error_map(char *str, t_data *data, int i)
{
	int j;

	j = 0;
	ft_printf(str);
	if (i >= 3)
	{
		while (data->map->tab_map[j])
			free(data->map->tab_map[j++]);
	}
	free_elem(data);
	exit(0);
}

void		*ft_error(char *str, t_data *data)
{
	ft_printf(str);
	if (data->elem != NULL)
		free_elem(data);
	exit(0);
}

void		init_struct(t_data *data)
{
	t_player	*player;
	t_map		*map;
	t_lmap		*line;

	map = ft_calloc(sizeof(t_map), 1);
	player = ft_calloc(sizeof(t_player), 1);
	data->elem->texture = (char **)malloc(sizeof(char *) * 5);
	data->map = map;
	data->player = player;
}
