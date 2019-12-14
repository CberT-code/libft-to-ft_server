/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:44:36 by cbertola          #+#    #+#             */
/*   Updated: 2019/12/01 17:06:15 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int        main()
{
    int        fd;
    int        fd2;
    char    *line;
    int        i;
    int ret;

    i = 0;
    fd = open("text.txt", O_RDONLY);
    fd2 = open("tata.txt", O_RDONLY);
    
	get_next_line(fd, &line);
        printf("%s\n", line);
    return (0);
}

