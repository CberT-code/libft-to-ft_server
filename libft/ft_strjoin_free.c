/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:27:36 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/20 21:33:47 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char		*ptr;
	int			u;
	long int	i;

	i = -1;
	if (!s1 && !s2)
		return (NULL);
	u = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = malloc(u * (sizeof(char) + 1))))
		return (NULL);
	while (*s1)
		ptr[++i] = *s1++;
	while (*s2)
		ptr[++i] = *s2++;
	ptr[++i] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (ptr);
}
