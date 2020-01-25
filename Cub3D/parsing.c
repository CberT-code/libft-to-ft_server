/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/25 17:54:45 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		*check_map(t_elem *elem)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (elem->map->tab_map[j][i])
		if (elem->map->tab_map[j][i++] != '1')
			return (ft_error_map(ERROR_MAP_F_WALL, elem, 3));
	i--;
	elem->map->line_len = ft_strlen(elem->map->tab_map[j]);
	while (++j < elem->map->tab_len)
	{
		if (elem->map->tab_map[j][0] != '1')
			return (ft_error_map(ERROR_MAP_S_WALL, elem, 3));
		if (elem->map->tab_map[j][i] != '1')
			return (ft_error_map(ERROR_MAP_FE_WALL, elem, 3));
	}
	i = 0;
	j--;
	while (elem->map->tab_map[j][i])
		if (elem->map->tab_map[j][i++] != '1')
			return (ft_error_map(ERROR_MAP_E_WALL, elem, 3));
	return (elem->map);
}

int			check_elem(char *str, t_elem *elem)
{
	if (elem->bit_elem < 255)
	{
		parsing_elem(str, elem);
		return (1);
	}
	if (ft_isdigit(*str))
	{
		elem->map->str_map = ft_strjoin_free(elem->map->str_map, str, 1);
		elem->map->str_map = ft_strsubstr_free(elem->map->str_map, " ");
		if (elem->map->line_len == 0)
			elem->map->line_len = ft_strlen(elem->map->str_map);
		elem->map->tab_len++;
		return (1);
	}
	if (!elem->map->str_map)
		return (1);
	return (0);
}

void		init_struct(t_elem *elem)
{
	t_player	*player;
	t_map		*map;

	map = malloc(sizeof(t_map));
	player = malloc(sizeof(t_player));
	elem->check = (char **)malloc(sizeof(char *) * 5);
	map->tab_len = 0;
	map->str_map = "";
	map->line_len = 0;
	elem->bit_elem = 0;
	elem->map = map;
	elem->player = player;
}

int			check_str_map(t_elem *elem)
{
	void *ptr;

	if (elem->bit_elem < 255)
		ptr = ft_error(ERROR_ELEM, elem);
	if (ft_strlen(elem->map->str_map) < 9 && ptr != NULL)
		ptr = ft_error_map(ERROR_MAP_NO, elem, 0);
	if (num_player(elem->map->str_map, elem) != 1 && ptr != NULL)
		ptr = NULL;
	if (ptr == NULL)
		return (0);
	return (1);
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
	if (check_str_map(elem) != 1)
		return (NULL);
	elem->map->tab_map = ft_splitnum(elem->map->str_map, elem->map->line_len);
	if (check_map(elem) == NULL)
		return (NULL);
	return (elem);
}

