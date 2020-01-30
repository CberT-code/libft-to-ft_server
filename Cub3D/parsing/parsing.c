/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/30 03:43:34 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			num_player2(t_data *data, int j, int h)
{
	if (data->map->tab_map[j][h] == 'N' || data->map->tab_map[j][h] == 'S' ||
			data->map->tab_map[j][h] == 'E' || data->map->tab_map[j][h] == 'W')
	{
		data->player->pos_y = h;
		data->player->pos_x = j;
		if (data->map->tab_map[j][h] == 'N')
			data->player->angle = 90;
		if (data->map->tab_map[j][h] == 'S')
			data->player->angle = -90;
		if (data->map->tab_map[j][h] == 'E')
			data->player->angle = 0;
		if (data->map->tab_map[j][h] == 'W')
			data->player->angle = 180;
		return (1);
	}
	return (0);
}

int			num_player(t_data *data, t_map *map)
{
	int		i;
	int		j;
	int		h;

	i = 0;
	j = 0;
	while (data->map->tab_map[j])
	{
		h = 0;
		while (data->map->tab_map[j][h])
		{
			if (num_player2(data, j, h) == 1)
				i++;
			h++;
		}
		j++;
	}
	if (i < 1)
		ft_error(ERROR_PLAYER_NO_POS, data);
	if (i > 1)
		ft_error(ERROR_PLAYER_EX_POS, data);
	return (i);
}

int			check_elem(char *str, t_elem *elem, t_data *data)
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
		map_str(str, data->map);
		return (1);
	}
	if (!i)
		return (1);
	return (0);
}

void		parsing(char *doc_map, t_data *data)
{
	t_elem		*elem;
	char		*line;
	int			fd;

	if (!doc_map)
		ft_error(ERROR_NO_FILE, NULL);
	elem = malloc(sizeof(t_elem));
	data->elem = elem;
	init_struct(data);
	fd = open(doc_map, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		check_elem(line, elem, data);
		free(line);
	}
	check_elem(line, elem, data);
	free(line);
	if (elem->bit_elem < 255)
		ft_error(ERROR_ELEM, data);
	full_map(data->map);
	check_map(data);
	num_player(data, data->map);
}
