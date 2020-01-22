/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:46:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/21 19:48:48 by cbertola         ###   ########.fr       */
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
