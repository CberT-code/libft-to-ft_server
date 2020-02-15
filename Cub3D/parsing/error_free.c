/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:46:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/15 11:46:22 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		free_elem(t_data *D)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (D->elem->bit_elem & (1 << i++))
			free(D->elem->texture[i - 1]);
	}
	free(D->elem->texture);
	free(D->map);
	free(D->P);
	free(D->elem);
}

void		*ft_error_map(char *str, t_data *D, int i)
{
	int j;

	j = 0;
	ft_printf(str);
	if (i >= 3)
	{
		while (D->map->tab_map[j])
			free(D->map->tab_map[j++]);
	}
	free_elem(D);
	exit(0);
}

void		*ft_error(char *str, t_data *D)
{
	ft_printf(str);
	if (D->elem != NULL)
		free_elem(D);
	exit(0);
}

void		init_struct(t_data *D)
{
	t_player	*P;
	t_map		*map;
	t_lmap		*line;

	map = ft_calloc(sizeof(t_map), 1);
	P = ft_calloc(sizeof(t_player), 1);
	D->elem->texture = (char **)malloc(sizeof(char *) * 5);
	D->map = map;
	D->P = P;
}
