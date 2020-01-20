/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:38:30 by cbertola          #+#    #+#             */
/*   Updated: 2020/01/16 17:10:43 by cbertola         ###   ########.fr       */
/*                                                                            */
#include <libc.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		charisfind(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*envoi(char *s1, char **line)
{
	char	*s2;
	char	*s3;
	int		i;
	int		j;

	i =  charisfind(s1,'\n'); 
	j =  ft_strlen(s1) - i;
	s2 = malloc(sizeof(char) * i + 1);
	s3 = malloc(sizeof(char) * j + 1);
	i = 0;
	j = 0;
	while (s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i++] = '\0';
	while (s1[i])
		s3[j++] = s1[i++];
	s3[j] = '\0';
	*line = s2;
	return (s3);
}

char	*join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	if(!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1) )))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char *stock;
	char *buff;
	int readc;

	if (BUFFER_SIZE < 1)
		return (-1);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	readc = read(fd, buff, BUFFER_SIZE);
	buff[readc] = '\0';
	stock = join(stock, buff);
	if (charisfind(stock,'\n') >= 0)
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
	int i = 40;

	fd = open("get_next_line.c", O_RDONLY);

	//get_next_line(fd, &line);
	while (get_next_line(fd, &line) == 1)
		printf("%s\n", line);

}
