/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/27 17:25:28 by cbertola         ###   ########.fr       */
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
	return (elem);
}

