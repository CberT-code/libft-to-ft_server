/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:27:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/14 14:53:57 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
int		ft_strlen(char *s1)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int		charisfind(char *str, char c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i++] == c)
			return (i);
	}
	return (-1);
}

char	*join(char *s1, char *s2)
{
	int i;
	int j;
	char *str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);

}

char	*envoi(char *s1, char **line)
{
	int i;
	int j;
	char *s2;
	char *s3;

	i = charisfind(s1, '\n');
	j = ft_strlen(s1) - i;
	if (!(s2 = malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (!(s3 = malloc(sizeof(char) * j + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i++] = '\0';
	*line = s2;
	while (s1[i])
		s3[j++] = s1[i++];
	s3[j] = '\0';
	free(s1);
	return (s3);
}

int		get_next_line(int fd, char **line)
{
	static char *stock;
	char *buff;
	int readc;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1 );
	readc = read(fd, buff, BUFFER_SIZE);
	buff[readc] = '\0';
	stock = join(stock, buff);
	if (charisfind(stock, '\n') >= 0)
	{
		stock = envoi(stock, line);
		return (1);
	}
	if (readc < BUFFER_SIZE)
	{
		*line = stock;
		return (0);
	}
	return (get_next_line(fd, line));

}

int		main()
{
	char *line;
	int fd;

	fd = open("test", O_RDONLY);
	while (get_next_line(fd, &line) != 0)
		printf("%s\n", line);
	return (0);

}
