/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:46:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/27 00:06:49 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		*free_elem(t_elem *elem)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (elem->bit_elem & (1 << i++))
			free(elem->check[i - 1]);
	}
	free(elem->check);
	free(elem->map);
	free(elem);
	return (NULL);
}

void		*ft_error_map(char *str, t_elem *elem, int i)
{
	int j;

	j = 0;
	ft_printf(str);
	if (i >= 3)
	{
		while (elem->map->tab_map[j])
			free(elem->map->tab_map[j++]);
		free(elem->map->tab_map);
	}
	if (i >= 1)
		free(elem->map->str_map);
	free_elem(elem);
	return (NULL);
}

void		*ft_error(char *str, t_elem *elem)
{
	ft_printf(str);
	if (elem != NULL)
		free_elem(elem);
	return (NULL);
}

void		init_struct(t_elem *elem)
{
	t_player	*player;
	t_map		*map;
	t_lmap		*line;

	map = malloc(sizeof(t_map));
	player = malloc(sizeof(t_player));
	elem->check = (char **)malloc(sizeof(char *) * 5);
	map->tab_line = 0;
	map->str_map = "";
	map->line_len = 0;
	elem->bit_elem = 0;
	elem->map = map;
	elem->player = player;
}
