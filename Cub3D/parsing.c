
#include "cub3d.h"

int		fill_int(int bit, char *str, t_info *ent)
{
	int		i;
	int		j;
	int		temp[3];

	i = 0;
	j = 0;
	printf("bit = %d\n", bit);
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	while (j < 2)
	{
		temp[j] = ft_atoi(str + i);
		i += ft_count_char_int(temp[j++], 10) + 1;
	}
	printf("bit = %d\n", bit);
	if (bit == 7)
	{
		ent->R[0] = temp[0];
		ent->R[1] = temp[1];
	}
	ent->check_bit = ent->check_bit | (1 << bit);
		printf("ent = %s\n", ent->check[bit]);
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
		temp = str + i;
	j = ft_strlen(temp);
		printf("bit = %d\n", bit);
	if (!(ent->check[bit] = malloc((sizeof(char) * j) + 1)))
		return (-1);
	ent->check_bit = ent->check_bit | (1 << bit);
	j = 0;
	while (temp[j])
	{
		ent->check[bit][j] = temp[j];
		j++;
	}
		ent->check[bit][j] = '\0';
		printf("ent = %s\n", ent->check[bit]);
	return (i + j);
}

void		parsing(char *str, t_info *ent)
{
	while (*str)
	{
		while (*str == ' ' || *str == '\n')
			str++;
		if (ft_start_str("NO ", str) > 0)
			str = str + fill_str(0, str, ent);
		if (ft_start_str("SO ", str) > 0)
			str = str + fill_str(1, str, ent);
		if (ft_start_str("WE ", str) > 0)
			str = str + fill_str(2, str, ent);
		if (ft_start_str("EA ", str) > 0)
			str = str + fill_str(3, str, ent);
		if (ft_start_str("S ", str) > 0)
			str = str + fill_str(4, str, ent);
		if (ft_start_str("F ", str) > 0)
			str = str + fill_int(5, str, ent);
		if (ft_start_str("C ", str) > 0)
			str = str + fill_int(6, str, ent);
		if (ft_start_str("R ", str) > 0)
			str = str + fill_int(7, str, ent);
		str++;
	}
}

int		check_ent(char *str, t_info *ent)
{
	parsing(str, ent);
	if (ent->check_bit != 255)
		return (-1);
	return (1);
}

int        main(int argc, char **argv)
{
    int			fd;
    char		*line;
	char		*str;
	t_info		ent;

	(void)argc;
	ent.check = (char **)malloc(sizeof(char *) * 8);
    fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
	   check_ent(line, &ent);
	}
		printf("enti = %s\n", ent.check[0]);
		printf("ent = %s\n", ent.check[1]);
		printf("ent = %s\n", ent.check[2]);
		printf("ent = %s\n", ent.check[3]);
		printf("ent = %s\n", ent.check[4]);
		printf("ent = %d\n", ent.R[0]);
		printf("ent = %d\n", ent.R[1]);
		printf("ent = %d\n", ent.F[0]);
		printf("ent = %d\n", ent.F[1]);
		printf("ent = %d\n", ent.F[2]);
		printf("ent = %d\n", ent.C[0]);
		printf("ent = %d\n", ent.C[1]);
		printf("ent = %d\n", ent.C[2]);
    return (0);
}
