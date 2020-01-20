/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:30:49 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/20 21:32:49 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsubstr(char *s1, char *sub)
{
	int		i;
	int		j;
	char	*s3;
	int		tab[256];

	j = 0;
	i = ft_strlen(s1) - ft_how_many(s1, sub);
	if (!(s3 = malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (*sub)
	{
		tab[(int)*sub] = 1;
		sub++;
	}
	while (*s1)
	{
		if (tab[(int)*s1] == 0)
			s3[j++] = *s1;
		s1++;
	}
	s3[j] = '\0';
	return (s3);
}
