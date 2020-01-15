/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:39:50 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/14 13:17:54 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <libc.h>

int BUFFER_SIZE = 1000;

typedef struct	s_list
{
	char	*buff;
	char	*stock;
	int		read;
}				t_list;
#endif
