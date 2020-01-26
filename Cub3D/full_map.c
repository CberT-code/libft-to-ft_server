/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:44:07 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/27 00:41:42 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		*check_map(t_elem *elem)
{
	int j;
	int size;

	j = 0;
	if (!(is_tab_full(elem->map->tab_map[j], '1')))
			return (ft_error_map(ERROR_MAP_F_WALL, elem, 3));
	size = ft_strlen(elem->map->tab_map[j]);
	while (++j < elem->map->line_len)
	{
		if (elem->map->tab_map[j][0] != '1')
			return (ft_error_map(ERROR_MAP_S_WALL, elem, 3));
		while (size < ft_strlen(elem->map->tab_map[j]))
			if (elem->map->tab_map[j][size++] != '1')
				return (ft_error_map(ERROR_MAP, elem, 3));
		while (size > ft_strlen(elem->map->tab_map[j]))
			if (elem->map->tab_map[j][size--] != '1')
				return (ft_error_map(ERROR_MAP, elem, 3));
		if (elem->map->tab_map[j][size] != '1')
			return (ft_error_map(ERROR_MAP_FE_WALL, elem, 3));
	}
	if (!(is_tab_full(elem->map->tab_map[--j], '1')))
			return (ft_error_map(ERROR_MAP_E_WALL, elem, 3));
	return (elem->map);
}

void		map_str(char *str, t_map *map)
{
	int		i;
	t_lmap	*line;
	t_lmap	*mouv;

	i = ft_strlen_no_ws(str);
	line = malloc(sizeof(t_map));
	line->str = ft_strsubstr(str, " ");
	line->size = i;
	map->tab_line++;
	line->next = 0;
	if (!map->line)
	{
		map->line = line;
	}
	else
	{
		mouv = map->line;
		while (mouv->next != 0)
		{
			mouv = mouv->next;
		}
		mouv->next = line;
	}
}

void		full_map(t_map *map)
{
	t_lmap	*mouv;
	int		i;

	i = 0;
	map->tab_map = (char **)malloc(sizeof(char *) * map->tab_line);
	mouv = map->line;
	while (mouv->next)
	{
		map->tab_map[i++] = mouv->str; 
		mouv = mouv->next;
	}		
		map->tab_map[i] = mouv->str; 


}
