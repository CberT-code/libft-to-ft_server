/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:44:36 by cbertola          #+#    #+#             */
/*   Updated: 2019/12/14 18:51:36 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int        main(int argc, char **argv)
{
    int        fd;
    char    *line;
	(void)argc;

    fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
       printf("%s\n", line);
    return (0);
}

