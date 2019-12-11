/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:27:36 by cbertola          #+#    #+#             */
/*   Updated: 2019/11/04 11:37:32 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	long int	u;
	long int	v;
	long int	i;

	i = -1;
	u = 0;
	v = 0;
	if (!(s1 && s2))
		return (NULL);
	if (s1)
		u = ft_strlen(s1);
	if (s2)
		v = ft_strlen(s2);
	if (!(ptr = malloc((u + v) * (sizeof(char) + 1))))
		return (NULL);
	if (s1)
		while (*s1)
			ptr[++i] = (char)*s1++;
	if (s2)
		while (*s2)
			ptr[++i] = (char)*s2++;
	ptr[++i] = '\0';
	return (ptr);
}
