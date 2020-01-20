
#include "cub3d.h"

int		ft_error(char *str)
{
	ft_printf(str);
	return (-1);
}

int		parsing_map(char *str, t_map *map)
{

	return (1);
}

int		check_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->tab_map[j])
		if (map->tab_map[0][i++] != '1')
			return (ft_error(ERROR_MAP_F_WALL));
	map->line_len = i;
	while (++j < map->tab_len)
	{
		if (map->tab_map[j][0] != '1')
			return (ft_error(ERROR_MAP_S_WALL));
		if (map->tab_map[j][i] != '1')
			return (ft_error(ERROR_MAP_FE_WALL));
	}
	i = 0;
	while (map->tab_map[j])
		if (map->tab_map[j][i++] != '1')
			return (ft_error(ERROR_MAP_E_WALL));
	return (1);
}


int		check_elem(char *str, t_elem *elem, t_map *map)
{
	if (elem->bit_elem < 255)
	{
		parsing_elem(str, elem);
		return (1);
	}
	if (*str == '1')
	{
		printf("testcoucou\n");
		map->str_map = ft_strjoin_free(map->str_map, str);
		map->tab_len++;
		return (1);
	}
	if (!map->str_map)
		return (1);
	return (0);
}

int        main(int argc, char **argv)
{
    int			fd;
    char		*line;
	char		*str;
	t_elem		*elem;
	t_map		*map;

	(void)argc;
	elem = malloc(sizeof(t_elem));
	map = malloc(sizeof(t_map));
	elem->check = (char **)malloc(sizeof(char *) * 8);
	elem->bit_elem = 0;
	map->tab_len = 0;
    fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
		   check_elem(line, elem, map);
	if (!map->str_map)
	{
		return (-1);
	}
	map->tab_map = ft_split(map->str_map, '\n');
	return (check_map(map));
}
