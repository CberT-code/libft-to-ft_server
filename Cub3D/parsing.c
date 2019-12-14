
#include "cub3d.h"

int		fill_int(int bit, char *str, t_info *ent)
{
	int		i;
	int		j;
	int		temp[3];

	i = 0;
	j = 0;
	while (*str++ != ' ')
		i++;
	while (*str++ == ' ')
		i++;
	while (j < 3)
	{
		temp[j] = ft_atoi(str);
		i += ft_count_char_int(temp[j], 10) + 1;
		str = str + i;
	}
	ent->check_bit = ent->check_bit | (1 << bit);
	return (i);
}

int		fill_str(int bit, char *str, t_info *ent)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	while (ft_isalpha(str[i]))
		temp[j++] = str[i++];
	temp[j] = '\0';
	j = ft_strlen(temp);
	if (!(ent->check[bit] = (char *)malloc(sizeof(char) * j)))
		return (-1);
	ent->check_bit = ent->check_bit | (1 << bit);
	j = 0;
	while (temp[j])
	{
		ent->check[bit][j] = temp[j];
		j++;
	}
	return (i);
}

void		parsing(char *str, t_info *ent)
{
	while (*str)
	{
		while (*str == ' ' || *str == '\n')
			str++;
		if (ft_start_str("NO ", str) > 0)
			fill_str(0, str, ent);
		if (ft_start_str("SO ", str))
			fill_str(1, str, ent);
		if (ft_start_str("WE ", str))
			fill_str(2, str, ent);
		if (ft_start_str("EA ", str))
			fill_str(3, str, ent);
		if (ft_start_str("S ", str))
			fill_str(4, str, ent);
		if (ft_start_str("F ", str))
			fill_int(5, str, ent);
		if (ft_start_str("C ", str))
		if (*str == 'C')
			fill_int(6, str, ent);
	}
}

int		check_ent(char *str, t_info *ent)
{
	ent->check = (char **)malloc(sizeof(char **) * 5);
	parsing(str, ent);
	if (ent->check_bit != 255)
		return (-1);
	return (1);
}

int        main(int argc, char **argv)
{
    int        fd;
    char    *line;
	char	*str;
	(void)argc;
	t_info ent;

    fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
       printf("%s\n", line);
	   check_ent(line, &ent);
	}
    return (0);
}
