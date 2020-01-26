/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/27 00:38:40 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_elem(char *str, t_elem *elem)
{
	int i ;

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
	full_map(elem->map);
	if (check_map(elem) == NULL)
		return (NULL); 
	return (elem);
}

