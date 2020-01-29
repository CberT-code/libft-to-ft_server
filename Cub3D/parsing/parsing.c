/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/29 21:39:03 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			num_player2(t_elem *elem, int j, int h)
{
	if (elem->map->tab_map[j][h] == 'N' || elem->map->tab_map[j][h] == 'S' ||
			elem->map->tab_map[j][h] == 'E' || elem->map->tab_map[j][h] == 'W')
	{
		elem->player->pos_y = h;
		elem->player->pos_x = j;
		if (elem->map->tab_map[j][h] == 'N')
			elem->player->angle = 90;
		if (elem->map->tab_map[j][h] == 'S')
			elem->player->angle = -90;
		if (elem->map->tab_map[j][h] == 'E')
			elem->player->angle = 0;
		if (elem->map->tab_map[j][h] == 'W')
			elem->player->angle = 180;
		return (1);
	}
	return (0);
}

int			num_player(t_elem *elem, t_map *map)
{
	int		i;
	int		j;
	int		h;

	i = 0;
	j = 0;
	while (map->tab_map[j])
	{
		h = 0;
		while (map->tab_map[j][h])
		{
			if (num_player2(elem, j, h) == 1)
				i++;
			h++;
		}
		j++;
	}
	if (i < 1)
		ft_error(ERROR_PLAYER_NO_POS, elem);
	if (i > 1)
		ft_error(ERROR_PLAYER_EX_POS, elem);
	return (i);
}

int			check_elem(char *str, t_elem *elem)
{
	int		i;

	i = 0;
	if (elem->bit_elem < 255)
	{
		parsing_elem(str, elem);
		return (1);
	}
	if (*str == '1')
	{
		i = 1;
		map_str(str, elem->map);
		return (1);
	}
	if (!i)
		return (1);
	return (0);
}

t_elem		*parsing(char *doc_map)
{
	t_elem		*elem;
	char		*line;
	int			fd;

	if (!doc_map)
		return (ft_error(ERROR_NO_FILE, NULL));
	elem = malloc(sizeof(t_elem));
	init_struct(elem);
	fd = open(doc_map, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		check_elem(line, elem);
		free(line);
	}
	check_elem(line, elem);
	free(line);
	if (elem->bit_elem < 255)
		ft_error(ERROR_ELEM, elem);
	full_map(elem->map);
	check_map(elem);
	num_player(elem, elem->map);
	return (elem);
}
