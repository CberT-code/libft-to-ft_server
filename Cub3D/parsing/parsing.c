/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/18 17:39:04 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			num_P2(t_data *D, int j, int h)
{
	if (D->map->tab_map[j][h] == 'N' || D->map->tab_map[j][h] == 'S' ||
			D->map->tab_map[j][h] == 'E' || D->map->tab_map[j][h] == 'W')
	{
		D->P->coord = ft_calloc(sizeof(t_coord), 1);
		D->P->coord->y = j;
		D->P->coord->x = h;
		if (D->map->tab_map[j][h] == 'N')
			D->P->alpha = M_PI_2;
		if (D->map->tab_map[j][h] == 'S')
			D->P->alpha = M_PI_2 * 3;
		if (D->map->tab_map[j][h] == 'E')
			D->P->alpha = 0;
		if (D->map->tab_map[j][h] == 'W')
			D->P->alpha = M_PI;
		return (1);
	}
	return (0);
}

int			num_P(t_data *D, t_map *map)
{
	int		i;
	int		j;
	int		h;

	i = 0;
	j = 0;
	while (D->map->tab_map[j])
	{
		h = 0;
		while (D->map->tab_map[j][h])
		{
			if (num_P2(D, j, h) == 1)
				i++;
			h++;
		}
		j++;
	}
	if (i < 1)
		ft_error(ERROR_P_NO_POS, D);
	if (i > 1)
		ft_error(ERROR_P_EX_POS, D);
	return (i);
}

int			check_elem(char *str, t_elem *elem, t_data *D)
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
		map_str(str, D->map);
		return (1);
	}
	if (!i)
		return (1);
	return (0);
}

void		parsing(char *doc_map, t_data *D)
{
	char		*line;
	int			fd;

	if (!doc_map)
		ft_error(ERROR_NO_FILE, NULL);
	D->elem = calloc(sizeof(t_elem), 1);
	D->M = calloc(sizeof(t_move), 1);
	init_struct(D);
	fd = open(doc_map, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		check_elem(line, D->elem, D);
		free(line);
	}
	check_elem(line, D->elem, D);
	free(line);
	if (D->elem->bit_elem < 255)
		ft_error(ERROR_ELEM, D);
	full_map(D->map);
	check_map(D);
	num_P(D, D->map);
}
