
int		ft_start_str(char *str1, char *str2)
{
	int i;

	i = 1;
	while(str1[i])
		if (str1[i] != str2[i])
			return (0);
	return (i);
}
